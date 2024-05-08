/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:03 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/08 22:09:26 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ahora que le paso por parametros los argumentos quiero comprobar que sean numeros*/
int	checker(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			r++;
			write(1, "r", 1);
		}
		else
			return (-1);
		i++;
	}
	return (r);
}

/*ahora necestio un funcion para crear un nodo i iguradar el valor de ft_aoti en el nodo*/
/*funcion addback para agregar el nodo a la lista */
/*funcion para recorer la lista en busca del mismo numero para ver si se repite*/

int	main(int ac, char *av[])
{
	int	i;
	int	flagr;

	i = 1;
	flagr = 0;
	if (ac >= 3)
	{
		while (av[i] != NULL)
		{
			write(1, "a", 1);
			if (checker(av[i]) != -1)
				ft_atoi(av[i], &flagr);
			else
				return (write(1, "CHECK\n", 6), 1);
			if (flagr == 1)
				return (write(1, "flag\n", 5), 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
