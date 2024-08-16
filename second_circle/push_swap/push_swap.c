/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:03 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/15 22:44:26 by cgomez-z         ###   ########.fr       */
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
	t_list *tmp;

	tmp = stack_a;
	while(tmp->next !=  NULL)
	{
		//printf("[%d]\n", stack_a->content);
		if (tmp->content > tmp->next->content)
			return(1);
		tmp = tmp->next;
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
	t_list	*tmp;
	int		num;
	int		i;

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
	//ft_printlst(&stack_a);
	return (stack_a);
}
/*
void  *get_index(t_list *stack_a)
{
	t_list *tmp;
	int i;

	tmp = stack_a;
	i = 0;
	while(tmp)
	{
		if(find_min(stack_a))
		{
			tmp->index = i++;
		}
		tmp = tmp->next;
	}
	return();
}*/

void check_sort(t_list **stack_a, t_list **stack_b)
{
	int size;

	size = lst_size(*stack_a);
	if(size == 2)
		ft_sort2(stack_a);
	else if(size == 3)
		ft_sort3(stack_a);
	else if(size == 4)
		ft_sort4(stack_a,stack_b);
	else if(size == 5)
		ft_sort5(stack_a,stack_b);
	else if(size > 5)
		ft_sort5(stack_a,stack_b);
}

int	main(int ac, char *av[])
{
	int		flagr;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
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
	ft_printlst(&a);
	ft_printlst(&b);
	//get_index(&a);
	check_sort(&a,&b);
	ft_printlst(&a);
	ft_printlst(&b);
	write(1, "\n", 1);
	return (0);
}
