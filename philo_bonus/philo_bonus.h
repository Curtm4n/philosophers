/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:06:54 by cdapurif          #+#    #+#             */
/*   Updated: 2022/01/04 17:37:55 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				nb_meal;
	pid_t			proc;
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
	t_philo			philo[250];
	sem_t			*forks;
	sem_t			*write;
	sem_t			*meal_time;
}				t_data;

int			error_case(char *str);
int			ft_atoi(char *str);
int			init_struct(t_data *data, int ac, char **av);
int			error_type(int ret);
int			start_simulation(t_data *data);
long long	get_time(void);
void		destroy_sem(t_data *data);
void		start_eating(t_philo *philo);
void		start_sleeping(t_philo *philo);
void		start_thinking(t_philo *philo);
void		print_action(t_data *data, int id, char *action);
void		smart_wait(t_philo *philo, int time, int eating);
void		die_while_action(t_philo *philo);

#endif
