/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:54 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/07 23:14:26 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->meal_time));
	print_action(data, philo->id, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(data->meal_time));
	wait(data, data->time_to_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
}

void	start_sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "is sleeping");
	wait(data, data->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(data, philo->id, "is thinking");
}
