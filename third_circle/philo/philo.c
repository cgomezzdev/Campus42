/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/20 03:38:17 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_philo_status(t_philo *philo, char *accion)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->dead_mutex);
	timestamp = get_timestamp() - philo->data->start_time;
	// Permite imprimir si nadie ha muerto, o si el mensaje es de muerte
	if (!philo->data->someone_die || strcmp(accion, "died!!!!!!!!!!") == 0)
		printf("%ld philo %i %s\n", timestamp, philo->n_philo, accion);
	pthread_mutex_unlock(&philo->data->dead_mutex);
}

void	check_dead(t_data *data)
{
	int		i;
	long	now;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_lock(&data->philos[i]->meal_mutex);
		now = get_timestamp();
		if (now - data->philos[i]->last_meal > data->philos[i]->ttd)
		{
			pthread_mutex_unlock(&data->philos[i]->meal_mutex);
			pthread_mutex_lock(&data->dead_mutex);
			if (!data->someone_die)
			{
				data->someone_die = 1;
				pthread_mutex_unlock(&data->dead_mutex);
				print_philo_status(data->philos[i], "died!!!!!!!!!!");
				return ;
			}
			pthread_mutex_unlock(&data->dead_mutex);
		}
		else
			pthread_mutex_unlock(&data->philos[i]->meal_mutex);
		i++;
	}
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->total_philos);
	while (i < data->total_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_create(&data->threads[i], NULL, routine, data->philos[i]);
		i++;
	}
}

int	main(void)
{
	t_data	data;
	int		i;

	i = 0;
	data.total_philos = 10;
	data.philos = malloc((data.total_philos) * sizeof(t_philo *));
	data.threads = malloc((data.total_philos) * sizeof(pthread_t));
	data.forks = malloc((data.total_philos) * sizeof(pthread_mutex_t));
	data.someone_die = 0;
	pthread_mutex_init(&data.dead_mutex, NULL);
	data.start_time = get_timestamp();
	init_forks(&data);
	while (i < data.total_philos)
	{
		data.philos[i] = malloc(sizeof(t_philo));
		data.philos[i]->data = &data;
		data.philos[i]->n_philo = i;
		data.philos[i]->ttd = 400;
		data.philos[i]->tte = 200;
		data.philos[i]->tts = 100;
		data.philos[i]->last_meal = data.start_time;
		pthread_mutex_init(&data.philos[i]->meal_mutex, NULL);
		data.philos[i]->own_fork = &data.forks[i];
		data.philos[i]->other_fork = &data.forks[(i + 1) % data.total_philos];
		i++;
	}
	printf("time %ld\n", get_timestamp() - data.start_time);
	init_philo(&data);
	while (!data.someone_die)
		check_dead(&data);
	i = 0;
	while (i < data.total_philos)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	return (0);
}
