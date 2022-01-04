/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:35:36 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/03 23:12:10 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_dead(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		sem_wait(data->meal_time);
		if ((get_time() - philo->last_meal) > data->time_to_die)
		{
			print_action(data, philo->id, "died");
			data->philo_dead = 1;
			sem_wait(data->write);
			exit(1);
		}
		sem_post(data->meal_time);
		if (data->philo_dead)
			break ;
		usleep(1000);
		if (philo->nb_meal >= data->nb_eat && data->nb_eat != -1)
			break ;
	}
	return (NULL);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	philo->last_meal = get_time();
	pthread_create(&(philo->death_check), NULL, check_dead, arg);
	if (philo->id % 2 == 0)
		usleep(data->time_to_eat * 1000);
	while (!data->philo_dead)
	{
		start_eating(philo);
		if (philo->nb_meal >= data->nb_eat && data->nb_eat != -1)
			break ;
		start_sleeping(philo);
		start_thinking(philo);
	}
	if (data->philo_dead)
		exit(1);
	exit(0);
}

void	wait_proc(t_data *data)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < data->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < data->nb_philo)
				kill(data->philo[i].proc, 15);
			break ;
		}
	}
}

int	start_simulation(t_data *data)
{
	int	i;

	data->launch_time = get_time();
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].proc = fork();
		if (data->philo[i].proc < 0)
			return (1);
		if (data->philo[i].proc == 0)
			life_cycle(&(data->philo[i]));
		usleep(100);
	}
	wait_proc(data);
	destroy_sem(data);
	return (0);
}
