/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/17 17:34:53 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo) // while try to take the forks
{
	printf("philo %i is thinking", philo->n_philo);
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
	return (NULL);
}

void	init_philo(t_data *data)
{
	int	p;
	int	i;

	i = 0;
	p = data->philos[0]->total_philos;
	while (i < p)
	{
		pthread_create(data->threads[i], NULL, routine, data->philos[i]);
		i++;
	}
}

int	main(void)
{
	t_data	data;
	int		i;

	i = 0;
	data.philos = malloc((10 + 1) * sizeof(t_philo *));
	data.threads = malloc((10 + 1) * sizeof(pthread_t *));
	while (i < 10)
	{
		data.philos[i] = malloc(sizeof(t_philo));
		data.philos[i]->total_philos = 11;
		data.philos[i]->ttt = 800;
		data.philos[i]->tte = 50;
		data.philos[i]->tts = 100;
	}
	init_philo(&data);
}
