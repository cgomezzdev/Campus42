/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:05:28 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/19 02:23:11 by cgomez-z         ###   ########.fr       */
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
	int tte;                     // time_to_eat
	int tts;                     // time_to_sleep
	int ttt;                     // time_to_think
	pthread_mutex_t *own_fork;   // fork for the philo
	pthread_mutex_t *other_fork; // fork for the other philo
	struct s_data *data;         // to have acces to data like the time
}					t_philo;

typedef struct s_data
{
	t_philo			**philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	long			start_time;
}					t_data;

#endif
