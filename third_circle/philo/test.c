/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:32:14 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/17 00:48:56 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int saltitos = 0;
pthread_mutex_t lock;

void	*jump(void *arg)
{
	int i;
	char *str1;

	str1=arg;
	i = 0;
	while(i < 10)
	{
		pthread_mutex_lock(&lock);
		printf("%s uno mutex loc\n",str1);
		i++;
		saltitos++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	ranita1;
	pthread_t	ranita2;
	char *str1;

	str1="ranita1";
	//pthread_create(thread, attr, routine, arg);
	pthread_create(&ranita1, NULL, jump, (void*)str1);// Creating a new thread.
	pthread_create(&ranita2, NULL, jump, NULL);// Creating a new thread.
	pthread_join(ranita1,NULL);// Wait for thread to finish
	pthread_join(ranita2,NULL);// Wait for thread to finish
	pthread_mutex_destroy(&lock);
	printf("Contador de saltitos final: %d\n",saltitos);
	return (0);
}
