/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/19 19:04:35 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_philo_status(t_philo *philo, char *accion)
{
    long timestamp;

    pthread_mutex_lock(&philo->data->dead_mutex);
    if (!philo->data->someone_die)
    {
        timestamp = get_timestamp() - philo->data->start_time;
        printf("%ld philo %i %s\n", timestamp, philo->n_philo, accion);
    }
    pthread_mutex_unlock(&philo->data->dead_mutex);
}


void    check_dead(t_data *data)
{
    int i = 0;

    while (i < data->total_philos && data->someone_die == 0)
    {
        pthread_mutex_lock(&data->philos[i]->meal_mutex);
        if (get_timestamp() - data->philos[i]->last_meal > data->philos[i]->ttd)
        {
            pthread_mutex_lock(&data->dead_mutex);
            if (!data->someone_die)
            {
                print_philo_status(data->philos[i], "died");
                data->someone_die = 1;
            }
            pthread_mutex_unlock(&data->dead_mutex);
        }
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
	pthread_mutex_init(&data.dead_mutex,NULL);
	data.start_time = get_timestamp();
	init_forks(&data);
	while (i < data.total_philos)
	{
		data.philos[i] = malloc(sizeof(t_philo));
		data.philos[i]->data = &data;
		data.philos[i]->n_philo = i;
		data.philos[i]->ttd = 300;
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
