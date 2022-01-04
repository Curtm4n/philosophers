/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:35:36 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/07 23:24:29 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(data->time_to_eat * 1000);
	while (!data->philo_dead)
	{
		if (philo->right_fork != philo->left_fork)
			start_eating(philo);
		if (data->everybody_ate)
			break ;
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}

void	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->philo[i].thread, NULL);
}

void	check_dead(t_data *data)
{
	int	i;

	while (!data->philo_dead && !data->everybody_ate)
	{
		i = -1;
		while (++i < data->nb_philo && !data->philo_dead)
		{
			pthread_mutex_lock(&(data->meal_time));
			if ((get_time() - data->philo[i].last_meal) > data->time_to_die)
			{
				print_action(data, data->philo[i].id, "died");
				data->philo_dead = 1;
			}
			pthread_mutex_unlock(&(data->meal_time));
			usleep(100);
		}
		if (data->philo_dead)
			break ;
		i = 0;
		while (data->nb_eat != -1 && \
				i < data->nb_philo && data->philo[i].nb_meal >= data->nb_eat)
			i++;
		if (i == data->nb_philo)
			data->everybody_ate = 1;
	}
}

int	start_simulation(t_data *data)
{
	int	i;

	data->launch_time = get_time();
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_create(&(data->philo[i].thread), NULL, life_cycle, \
				&(data->philo[i])))
			return (1);
		data->philo[i].last_meal = get_time();
	}
	check_dead(data);
	join_threads(data);
	destroy_mutex(data);
	return (0);
}
