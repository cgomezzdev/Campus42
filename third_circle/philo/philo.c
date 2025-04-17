/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/17 01:24:57 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	printf("a\n");
}

void init_philo(int p)
{
	pthread_t	philo[p];
	int			i;

	i = 0;
	while (i <= p)
	{
		pthread_create(&philo[i], NULL, routine, NULL);
		i++;
	}
}

int	main(void)
{
	int	p;
	int	ttd;
	int	tte;
	int	tts;

	p = 50;
	ttd = 800;
	tte = 50;
	tts = 100;
	init_philo(p);
}
