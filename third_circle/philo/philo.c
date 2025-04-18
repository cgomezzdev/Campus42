/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/18 18:57:10 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo) // while try to take the forks
{
	printf("philo %i is thinking\n", philo->n_philo);
}

void	sleeping(t_philo *philo) // while the time to sleep is not finish
{
	printf("philo %i is sleeping\n", philo->n_philo);
	usleep(philo->tts * 1000);
	return ;
}

void	eating(t_philo *philo)
// try to take the forks when he have it he eat when he finish take of the forks
{
	printf("philo %i has taken a fork\n", philo->n_philo);
	pthread_mutex_lock(philo->own_fork);
	pthread_mutex_lock(philo->other_fork);
	printf("philo %i has taken a fork\n", philo->n_philo);
	printf("philo %i is eating\n", philo->n_philo);
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->other_fork);
}

void	*routine(void *arg) // call the functions eating sleeping and thinking
{
	t_philo *philo = (t_philo *)arg;


	printf("philo %i is test\n", philo->n_philo);
	usleep(30);
	printf("philo %i is eating2\n", philo->n_philo);
	if(philo->n_philo % 2 == 1)
		usleep(philo->tte/2*1000);
	eating(philo);
	sleeping(philo);
	thinking(philo);
	return (NULL);
}

void	init_philo(t_data *data, int total)
{
	int	i;

	i = 0;
	while (i <= total)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i <= total)
	{
		pthread_create(&data->threads[i], NULL, routine, data->philos[i]);
		i++;
	}
}

int	main(void)
{
	t_data	data;
	int		i;
	int		total_philos;

	i = 0;
	total_philos = 10;
	data.philos = malloc((total_philos) * sizeof(t_philo *));
	data.threads = malloc((total_philos) * sizeof(pthread_t));
	//data.forks = malloc((total_philos) * sizeof(pthread_mutex_t));
	while (i < total_philos)
	{
		data.philos[i] = malloc(sizeof(t_philo));
		data.philos[i]->n_philo = i;
		data.philos[i]->ttt = 800;
		data.philos[i]->tte = 200;
		data.philos[i]->tts = 100;
		data.philos[i]->tts = 100;
		data.philos[i]->tts = 100;
		data.philos[i]->own_fork = &data.forks[i];
		data.philos[i]->other_fork = &data.forks[(i + 1) % total_philos];
		i++;
	}
	init_philo(&data, total_philos);
//	i = 0;
	/*while (i < total_philos)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}*/
	return (0);
}
