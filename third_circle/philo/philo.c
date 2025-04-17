/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/17 16:01:54 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo) // while try to take the forks
{
	printf("philo X is thinking");
}

void	sleeping(t_philo *philo) // while the time to sleep is not finish
{
	printf("philo X is sleeping");
	while (philo->tts > -1) // ill use usleep for this
	{
		philo->tts--;
	}
	return ;
}

void	eating(t_philo *philo)
		// try to take the forks when he have it he eat when he finish take of the forks
{
	pthread_mutex_lock(philo->own_fork);
	pthread_mutex_lock(philo->other_fork);
	printf("philo X has taken a fork");
	while (philo->tte > -1) // ill use usleep for this
	{
		philo->tte--;
	}
	printf("philo X is eating");
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->other_fork);
}

void	*routine(void *arg) // call the functions eating sleeping and thinking
{
	t_philo *philo = (t_philo *)arg;
	printf("a\n");
	eating(philo);
	sleeping(philo);
	thinking(philo);
}

void	init_philo(t_data *data)
{
	int p;
	int			i;

	i = 0;
	p = data->philos[0]->total_philos;
	while (i < p)
	{
		pthread_create(&data->philos[i], NULL, routine, data->philos);
		i++;
	}
}

int	main(void)
{
	t_data	data;

	data.philos.n_philo = 10;
	data.philos.ttd = 800;
	data.philos.tte = 50;
	data.philos.tts = 100;
	init_philo(&data);
}
