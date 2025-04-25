/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:05:28 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/25 15:24:16 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				n_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				num_min_meals;
	long			last_meal;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*own_fork;
	pthread_mutex_t	*other_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_philo			**philos;
	pthread_t		*threads;
	pthread_t		monitor_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	fed_mutex;
	long			start_time;
	int				someone_die;
	int				total_fed_philos;
	int				total_philos;
}					t_data;

int					check_over(t_data *data);
int					ft_strcmp(char *s1, char *s2);
int					parser(int ac, char **av);
int					ft_atoi(char *s);
int					check_dead(t_data *data);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
void				eating(t_philo *philo);
void				*routine(void *arg);
void				destroy_and_free(t_data *data);
void				init_philos_data(t_data *data, char **av);
void				init_forks(t_data *data);
void				init_philo_routine(t_data *data);
void				print_philo_status(t_philo *philo, char *action);
long				get_timestamp(void);

#endif
