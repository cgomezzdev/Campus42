/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:03 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/11 20:21:33 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ahora que le paso por parametros los argumentos quiero comprobar que sean numeros*/
static int	checker_digits(char *str)
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
			//write(1, "r", 1);
		}
		else
			return (-1);
		i++;
	}
	return (r);
}

/*Ahora que he confirmado que son numeros los paso a int con el atoi,en el cual tengo una
 flag que me dice si alguno de los numeros se pasa del max y el min int si esto pasa retorna error.*/

static int	arg_checker(char **av, int flagr)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		//write(1, "a", 1);
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

/*ahora necestio un funcion para crear un nodo i iguradar el valor de ft_aoti en el nodo*/
/*funcion addback para agregar el nodo a la lista */
/*funcion para recorer la lista en busca del mismo numero para ver si se repite*/

void free_lst(t_list *stack)
{
	t_list *node;

	while(stack != NULL)
	{
		//write(1,"a\n", 2);
		node = stack;
		stack = stack->next;
		free(node);
	}
	exit(1);
}

int lst_sorted(t_list *stack_a)
{
	while(stack_a->next !=  NULL)
	{
		//printf("[%d]\n", stack_a->content);
		if (stack_a->content > stack_a->next->content)
			return(1);
		stack_a = stack_a->next;
	}
	return(0);
}

/*
void print_stack(t_list *stack)
{
	int i; 

	i = 0;
	while(stack != NULL)
	{
		printf("[%d] - %d\n", i++, stack->content);
		stack = stack->next;
	}
}*/

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
		//print_stack(stack_a);
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
	return (stack_a);
}

int	main(int ac, char *av[])
{
	int		flagr;
	t_list	*a;

	a = NULL;
	flagr = 0;
	if (ac == 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (arg_checker(av, flagr) == 1)
		a = make_stack_a(av);
	if(lst_sorted(a) == 0)
	{
		printf("stack already sorted!\n");
		free_lst(a);
	}
	if(a)
	ft_printlst(&a);
	write(1, "\n", 1);
	return (0);
}
