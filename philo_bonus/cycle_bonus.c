/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:54 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/03 23:15:44 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	print_action(data, philo->id, "has taken a fork");
	sem_wait(data->forks);
	print_action(data, philo->id, "has taken a fork");
	sem_wait(data->meal_time);
	print_action(data, philo->id, "is eating");
	philo->last_meal = get_time();
	sem_post(data->meal_time);
	smart_wait(data, data->time_to_eat);
	philo->nb_meal++;
	sem_post(data->forks);
	sem_post(data->forks);
}

void	start_sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "is sleeping");
	smart_wait(data, data->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "is thinking");
}
