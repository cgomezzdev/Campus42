/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:43:02 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/19 18:43:34 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo) // while try to take the forks
{
	print_philo_status(philo, "is thinking");
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
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->meal_mutex);
	usleep(philo->tte * 1000);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->other_fork);
}

void	*routine(void *arg) // call the functions eating sleeping and thinking
{
	t_philo *philo = (t_philo *)arg;

	usleep(100);
	if (philo->n_philo % 2 == 1)
		usleep((philo->tte / 2) * 1000);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
