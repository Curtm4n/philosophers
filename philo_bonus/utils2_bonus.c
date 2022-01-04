/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:05:07 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/04 18:12:18 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	smart_wait(t_philo *philo, int time, int eating)
{
	t_data		*data;
	long long	i;

	data = philo->data;
	i = get_time();
	while (get_time() - i < time)
	{
		if (eating)
		{
			sem_wait(data->meal_time);
			die_while_action(philo);
			sem_post(data->meal_time);
		}
		else
			die_while_action(philo);
		usleep(10);
	}
}
