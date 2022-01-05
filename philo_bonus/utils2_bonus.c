/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:05:07 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/05 17:01:32 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	smart_wait(t_philo *philo, int time)
{
	t_data		*data;
	long long	i;

	data = philo->data;
	i = get_time();
	if (i - philo->last_meal + time > data->time_to_die)
	{
		usleep(1000 * (time - \
			((i - philo->last_meal + time) - data->time_to_die)));
		die_while_action(philo);
	}
	else
	{
		while (get_time() - i < time)
		{
			usleep(10);
		}
	}
}
