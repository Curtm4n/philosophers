/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:06:54 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/07 23:13:30 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				left_fork;
	int				right_fork;
	int				nb_meal;
	pthread_t		thread;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				everybody_ate;
	long long		launch_time;
	int				philo_dead;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	meal_time;
}				t_data;

int			error_case(char *str);
int			ft_atoi(char *str);
int			init_struct(t_data *data, int ac, char **av);
int			error_type(int ret);
int			start_simulation(t_data *data);
long long	get_time(void);
void		free_struct(t_data *data);
void		destroy_mutex(t_data *data);
void		start_eating(t_philo *philo);
void		start_sleeping(t_philo *philo);
void		start_thinking(t_philo *philo);
void		print_action(t_data *data, int id, char *action);
void		wait(t_data *data, int time);

#endif
