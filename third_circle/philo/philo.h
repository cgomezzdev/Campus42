/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:05:28 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/23 17:08:35 by cgomez-z         ###   ########.fr       */
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
	int n_philo;                 // philo id;
	int ttd;                     // time_to_die
	int tte;                     // time_to_eat
	int tts;                     // time_to_sleep
	int num_min_meals;           // time_to_sleep
	long last_meal;              // last time that a philo eat
	pthread_mutex_t meal_mutex;  // fork for the update meal value
	pthread_mutex_t *own_fork;   // fork for the philo
	pthread_mutex_t *other_fork; // fork for the other philo
	struct s_data *data;         // to have acces to data like the time
}					t_philo;

typedef struct s_data
{
	t_philo			**philos;
	pthread_t		*threads;
	pthread_t		god_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	fed_mutex;
	long			start_time;
	int				someone_die;
	int				total_fed_philos;
	int				total_philos;
}					t_data;

int					parser(int ac, char **av);
int					ft_atoi(char *s);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
void				eating(t_philo *philo);
void				*routine(void *arg);
void				destroy_and_free(t_data *data);

void	print_philo_status(t_philo *philo, char *action); // se escribe action
long				get_timestamp(void);

#endif
