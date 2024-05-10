/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:40:56 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/06 14:48:54 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_min(int n1, int n2)
{
	int	m;

	m = n1;
	if (n2 < n1)
		return (n2);
	return (m);
}

int	ft_pgcd(int n1, int n2)
{
	int	tmp;
	int	i;
	int	min;

	// Consigo el nuemro mas pqueño de los dos para buscar divisior hasta ese numero.
	min = ft_min(n1, n2);
	i = 1;
	while (i <= min)
	{
		// Si el el reste del numero en los dos casos es iugal a 0 guarar en tmp.
		if (n1 % i == 0 && n2 % i == 0)
			tmp = i;
		i++;
	}
	return (tmp);
}

int	main(int ac, char *av[])
{
	int	i;
	int	pgcd;

	i = 0;
	if (ac == 3)
	{
		pgcd = ft_pgcd(atoi(av[1]), atoi(av[2]));
		printf("%i", pgcd);
	}
	printf("\n");
	return (0);
}
