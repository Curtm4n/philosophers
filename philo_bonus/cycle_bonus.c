/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:54 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/06 15:46:03 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	die_while_action(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "died");
	data->philo_dead = 1;
	sem_wait(data->write);
	exit(1);
}

void	start_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	print_action(data, philo->id, "has taken a fork");
	if (data->nb_philo == 1)
		smart_wait(philo, data->time_to_die + 10);
	sem_wait(data->forks);
	print_action(data, philo->id, "has taken a fork");
	print_action(data, philo->id, "is eating");
	smart_wait(philo, data->time_to_eat);
	philo->last_meal = get_time();
	philo->nb_meal++;
	sem_post(data->forks);
	sem_post(data->forks);
}

void	start_sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "is sleeping");
	smart_wait(philo, data->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "is thinking");
}
