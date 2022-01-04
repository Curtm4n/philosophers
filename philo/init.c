/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:26:37 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/07 22:46:56 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->write), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_time), NULL))
		return (1);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
		return (1);
	memset(data->philo, 0, data->nb_philo * sizeof(t_philo));
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].right_fork = i;
		data->philo[i].left_fork = (i + 1) % data->nb_philo;
		data->philo[i].data = data;
	}
	return (0);
}

int	init_struct(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	if (data->nb_philo < 1 || data->time_to_die < 0 || data->time_to_eat < 0 \
		|| data->time_to_sleep < 0)
		return (1);
	if (ac == 5)
	{
		data->nb_eat = ft_atoi(av[4]);
		if (data->nb_eat < 0)
			return (1);
	}
	else
		data->nb_eat = -1;
	if (init_philo(data))
		return (2);
	if (init_mutex(data))
		return (3);
	return (0);
}
