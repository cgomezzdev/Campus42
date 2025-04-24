/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/24 18:59:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_status(t_philo *philo, char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->dead_mutex);
	timestamp = get_timestamp() - philo->data->start_time;
	// Permite imprimir si nadie ha muerto, o si el mensaje es de muerte
	if (!philo->data->someone_die || ft_strcmp(action, "died!!!!!!") == 0)
		printf("%ld philo %i %s\n", timestamp, philo->n_philo, action);
	pthread_mutex_unlock(&philo->data->dead_mutex);
}

int	check_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
	{
		pthread_mutex_lock(&data->philos[i]->meal_mutex);
		if (get_timestamp() - data->philos[i]->last_meal > data->philos[i]->ttd)
		{
			pthread_mutex_unlock(&data->philos[i]->meal_mutex);
			pthread_mutex_lock(&data->dead_mutex);
			if (!data->someone_die)
			{
				data->someone_die = 1;
				pthread_mutex_unlock(&data->dead_mutex);
				print_philo_status(data->philos[i], "died!!!!!!");
				return (1);
			}
			pthread_mutex_unlock(&data->dead_mutex);
		}
		else
			pthread_mutex_unlock(&data->philos[i]->meal_mutex);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->fed_mutex);
		if (data->total_fed_philos == data->total_philos)
		{
			pthread_mutex_unlock(&data->fed_mutex);
			pthread_mutex_lock(&data->dead_mutex);
			data->someone_die = 1;
			pthread_mutex_unlock(&data->dead_mutex);
			printf("WE AR FULL\n");
			break ;
		}
		pthread_mutex_unlock(&data->fed_mutex);
		if (check_dead(data))
			break ;
	}
	//usleep(500);
	return (NULL);
}

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (parser(ac, av) == 1)
		return (printf("invalid arguments\n"), 1);
	data.someone_die = 0;
	data.total_fed_philos = 0;
	pthread_mutex_init(&data.dead_mutex, NULL);
	pthread_mutex_init(&data.fed_mutex, NULL);
	data.start_time = get_timestamp();
	init_philos_data(&data, av);
	init_forks(&data);
	init_philo_routine(&data);
	usleep(100);
	pthread_create(&data.monitor_thread, NULL, monitor, &data);
	i = 0;
	while (i < data.total_philos)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	pthread_join(data.monitor_thread, NULL);
	destroy_and_free(&data);
	return (0);
}
