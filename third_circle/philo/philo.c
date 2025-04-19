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

// ideas para saber cuando un philio a muerto por no comer
// add una flag que se active cuando come y de desactive cuando deja de comer o
// add una nueva variable a la struct que guarde el tiempo de la ultima vez que comio
// y si el tiempo actual
//	- el tiempo de la ultima comida es mas pequeny que el ttd entonces
// el sabes si el philo muero por no comer.

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

void	check_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos && data->someone_die == 0)
	{
		if (get_timestamp() - data->philos[i]->last_meal > data->philos[i]->ttd)
		{
			print_philo_status(data->philos[i], "die!!!!!!!!!!!!!!!!!!!!!!!!!");
			data->someone_die = 1;
		}
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
	data.start_time = get_timestamp();
	while (i < data.total_philos)
	{
		data.philos[i] = malloc(sizeof(t_philo));
		data.philos[i]->data = &data;
		data.philos[i]->n_philo = i;
		data.philos[i]->ttd = 300;
		data.philos[i]->tte = 200;
		data.philos[i]->tts = 100;
		data.philos[i]->last_meal = data.start_time;
		data.philos[i]->own_fork = &data.forks[i];
		data.philos[i]->other_fork = &data.forks[(i + 1) % data.total_philos];
		i++;
	}
	init_forks(&data);
	printf("time %ld\n", get_timestamp() - data.start_time);
	init_philo(&data);
	while (1)
		check_dead(&data);
	i = 0;
	while (i < data.total_philos)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	return (0);
}
