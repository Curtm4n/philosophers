/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:35:36 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/04 18:12:52 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*life_cycle(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	philo->last_meal = get_time();
	if (philo->id % 2 == 0)
		usleep(data->time_to_eat * 1000);
	while (!data->philo_dead)
	{
		start_eating(philo);
		if (philo->nb_meal >= data->nb_eat && data->nb_eat != -1)
			exit(1);
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
				kill(data->philo[i].proc, 9);
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
