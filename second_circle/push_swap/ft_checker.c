/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:20:32 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/23 01:20:37 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ahora que le paso por parametros los argumentos quiero comprobar que sean numeros*/
int	checker_digits(char *str)
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
			// write(1, "r", 1);
		}
		else
			return (-1);
		i++;
	}
	return (r);
}

/*Ahora que he confirmado que son numeros los paso a int con el atoi,en el cual tengo una
 flag que me dice si alguno de los numeros se pasa del max y el min int si esto pasa retorna error.*/

int	arg_checker(char **av, int flagr)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		// write(1, "a", 1);
		// printf("Numeros: %s\n", av[i]);
		if (checker_digits(av[i]) != -1)
			ft_atoi(av[i], &flagr);
		else
			return (write(1, "CHECK\n", 6), -1);
		if (flagr == 1)
			return (write(1, "flag\n", 5), -1);
		i++;
	}
	return (1);
}

int	lst_sorted(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		// printf("[%d]\n", stack_a->content);
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_dupe(t_list *stack_a, int num)
{
	if (!stack_a)
		return (0);
	while (stack_a != NULL)
	{
		if (stack_a->content == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
