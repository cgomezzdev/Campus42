/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/19 02:52:41 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_philo_status(t_philo *philo, char *accion)
{
	long	timestamp;

	timestamp = get_timestamp() - philo->data->start_time;
	printf("%ld philo %i %s\n", timestamp, philo->n_philo, accion);
}

void	thinking(t_philo *philo) // while try to take the forks
{
	print_philo_status(philo, "is thinking");
	usleep(philo->ttt * 1000);
}

void	sleeping(t_philo *philo) // while the time to sleep is not finish
{
	print_philo_status(philo, "is sleeping");
	usleep(philo->tts * 1000);
	return ;
}

void	eating(t_philo *philo)
// try to take the forks when he have it he eat when he finish take of the forks
{
	pthread_mutex_lock(philo->own_fork);
	print_philo_status(philo, "has taken his own fork");
	pthread_mutex_lock(philo->other_fork);
	print_philo_status(philo, "has taken his the other fork");
	print_philo_status(philo, "is eating");
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->other_fork);
}

void	*routine(void *arg) // call the functions eating sleeping and thinking
{
	t_philo *philo = (t_philo *)arg;

	usleep(100);
	if (philo->n_philo % 2 == 1)
		usleep(philo->tte / 2 * 1000);
	eating(philo);
	sleeping(philo);
	thinking(philo);
	return (NULL);
}

void	init_forks(t_data *data, int total)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * total);
	while (i < total)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data, int total)
{
	int	i;

	i = 0;
	while (i < total)
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
	data.forks = malloc((total_philos) * sizeof(pthread_mutex_t));
	while (i < total_philos)
	{
		data.philos[i] = malloc(sizeof(t_philo));
		data.philos[i]->data = &data;
		data.philos[i]->n_philo = i;
		data.philos[i]->tte = 200;
		data.philos[i]->tts = 100;
		data.philos[i]->ttt = 800;
		data.philos[i]->own_fork = &data.forks[i];
		data.philos[i]->other_fork = &data.forks[(i + 1) % total_philos];
		i++;
	}
	init_forks(&data, total_philos);
	data.start_time = get_timestamp();
	printf("time %ld\n", get_timestamp() - data.start_time);
	init_philo(&data, total_philos);
	i = 0;
	while (i < total_philos)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	return (0);
}
