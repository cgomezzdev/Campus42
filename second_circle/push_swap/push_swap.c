/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:03 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/14 21:25:48 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ahora que le paso por parametros los argumentos quiero comprobar que sean numeros*/
static int	checker(char *str)
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

static int	arg_checker(char *av, int flagr)
{
	int	i;

	i = 0;
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
	return (1);
}

/*ahora necestio un funcion para crear un nodo i iguradar el valor de ft_aoti en el nodo*/
/*funcion addback para agregar el nodo a la lista */
/*funcion para recorer la lista en busca del mismo numero para ver si se repite*/

static t_list	*make_stack_a(char **av)
{
	t_list	*stack_a;
	int		num;
	int		i;
	t_list	*tmp;

	stack_a = NULL;
	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i], &num);
		tmp = ft_newlst(num);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}

int	main(int ac, char *av[])
{
	int	i;
	int	flagr;

	i = 1;
	flagr = 0;
	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (arg_checker(av[i], flagr) == 1)
	{
		while (av[i])
			make_stack_a(av[i]);
	}
	write(1, "\n", 1);
	return (0);
}
