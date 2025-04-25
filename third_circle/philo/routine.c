/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:43:02 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/25 15:23:40 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_philo_status(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	print_philo_status(philo, "is sleeping");
	usleep(philo->tts * 1000);
	return ;
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->own_fork);
	print_philo_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->other_fork);
	print_philo_status(philo, "has taken a fork");
	print_philo_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->meal_mutex);
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->other_fork);
}

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->own_fork);
	print_philo_status(philo, "has taken a fork");
	usleep(philo->ttd * 1000);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_timestamp() - philo->data->start_time - philo->ttd;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		check_min_meals;

	philo = (t_philo *)arg;
	check_min_meals = 0;
	usleep(100);
	if (philo->data->total_philos == 1)
		return (handle_one_philo(philo), NULL);
	if (philo->n_philo % 2 == 1)
		usleep((philo->tte / 2) * 1000);
	while (!check_over(philo->data))
	{
		eating(philo);
		check_min_meals++;
		if (check_min_meals == philo->num_min_meals)
		{
			pthread_mutex_lock(&philo->data->fed_mutex);
			philo->data->total_fed_philos++;
			pthread_mutex_unlock(&philo->data->fed_mutex);
			break ;
		}
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
