/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:03 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/23 01:20:11 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ahora necestio un funcion para crear un nodo i iguradar el valor de ft_aoti en el nodo*/
/*funcion addback para agregar el nodo a la lista */
/*funcion para recorer la lista en busca del mismo numero para ver si se repite*/

static t_list	*make_stack_a(char **av)
{
	t_list	*stack_a;
	t_list	*tmp;
	int		num;
	int		i;

	stack_a = NULL;
	i = 1;
	while (av[i])
	{
		// print_stack(stack_a);
		num = ft_atoi(av[i], 0);
		printf("Num nodo: %i\n", num);
		if (check_dupe(stack_a, num))
		{
			printf("error dupe\n");
			free_lst(stack_a);
		}
		tmp = ft_newlst(num);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	// ft_printlst(&stack_a);
	return (stack_a);
}

void	check_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 2)
		ft_sort2(stack_a);
	else if (size == 3)
		ft_sort3(stack_a);
	else if (size == 4)
		ft_sort4(stack_a, stack_b);
	else if (size == 5)
		ft_sort5(stack_a, stack_b);
	else if (size > 5)
	{
		get_index_num(stack_a);
		radix_sort(stack_a, stack_b);
	}
}

int	main(int ac, char *av[])
{
	int		flagr;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	flagr = 0;
	if (ac <= 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (arg_checker(av, flagr) == 1)
		a = make_stack_a(av);
	if (lst_sorted(a) == 0)
	{
		printf("stack already sorted!\n");
		free_lst(a);
	}
	ft_printlst(&a);
	ft_printlst(&b);
	check_sort(&a, &b);
	ft_printlst(&a);
	ft_printlst(&b);
	write(1, "\n", 1);
	return (0);
}
