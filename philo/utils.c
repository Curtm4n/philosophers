/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:27:45 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/07 21:36:22 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&(data->write));
	if (!(data->philo_dead))
		printf("%lld %d %s\n", get_time() - data->launch_time, id, action);
	pthread_mutex_unlock(&(data->write));
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write));
	pthread_mutex_destroy(&(data->meal_time));
}

void	free_struct(t_data *data)
{
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_atoi(char *str)
{
	int	nb;

	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb);
}
