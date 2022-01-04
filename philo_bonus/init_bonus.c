/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:26:37 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/03 23:07:30 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sem(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/meal_time");
	data->forks = sem_open("/forks", O_CREAT, S_IRWXU, data->nb_philo);
	data->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	data->meal_time = sem_open("/meal_time", O_CREAT, S_IRWXU, 1);
	if (data->forks <= 0 || data->write <= 0 || data->meal_time <= 0)
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
	if (data->nb_eat == 1)
		data->nb_eat++;
	if (init_philo(data))
		return (2);
	if (init_sem(data))
		return (3);
	return (0);
}
