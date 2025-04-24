/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:28:56 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/24 18:15:50 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(char *s)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (s[i])
	{
		num = (num * 10) + s[i] - '0';
		i++;
	}
	return (num);
}

void	destroy_and_free(t_data *data)
{
	int	i;

	// Destruir mutex y liberar cada filósofo
	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_destroy(&data->philos[i]->meal_mutex);
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	// Destruir y liberar los forks (mutexes)
	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	// Destruir mutexes globales
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->fed_mutex);
	// Liberar array de hilos
	free(data->threads);
}
