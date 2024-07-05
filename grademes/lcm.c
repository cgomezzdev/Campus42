/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:01:05 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/14 17:46:26 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funcion para encontrar el minimo comun multiplo.
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	max;
	if(a == 0 || b == 0)
		return(0);

	//hacemos este if para encontrar el numero mas grande de los 2
	if (a > b)
		max = a;
	else
		max = b;
	//haces while 1 que es igual a true para que sea infinito hasta que la condicion
	//del if de dentro se cumpla entonces retornanar el valor.
	while (1)
	{
		if (max % a == 0 && max % b == 0)
			return (max);
		++max;
	}
}

#include <stdio.h>

int	main(void)
{
	printf("%u\n", lcm(0, 0));
}
