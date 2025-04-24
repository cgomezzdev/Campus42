/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 02:11:50 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/24 02:27:27 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos_data(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->total_philos = ft_atoi(av[1]);
	data->philos = malloc((data->total_philos) * sizeof(t_philo *));
	data->threads = malloc((data->total_philos) * sizeof(pthread_t));
	data->forks = malloc((data->total_philos) * sizeof(pthread_mutex_t));
	while (i < data->total_philos)
	{
		data->philos[i] = malloc(sizeof(t_philo));
		data->philos[i]->data = data;
		data->philos[i]->n_philo = i + 1;
		data->philos[i]->ttd = ft_atoi(av[2]);
		data->philos[i]->tte = ft_atoi(av[3]);
		data->philos[i]->tts = ft_atoi(av[4]);
		if (av[5])
			data->philos[i]->num_min_meals = ft_atoi(av[5]);
		data->philos[i]->last_meal = data->start_time;
		pthread_mutex_init(&data->philos[i]->meal_mutex, NULL);
		data->philos[i]->own_fork = &data->forks[i];
		data->philos[i]->other_fork = &data->forks[(i + 1)
			% data->total_philos];
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
