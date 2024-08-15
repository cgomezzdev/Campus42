/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:36:41 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/15 22:46:45 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_list **stack_a)
{
	t_list	*tmp;
	int		ref;

	tmp = *stack_a;
	ref = tmp->content;
	while (tmp)
	{
		if (ref > tmp->content)
			ref = tmp->content;
		tmp = tmp->next;
	}
	while (stack_a)
	{
		if ((*stack_a)->content == ref)
			(*stack_a)->index++;
		(*stack_a) = (*stack_a)->next;
	}
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (stack_1)
	{
		tmp = *stack_1;
		(*stack_1) = (*stack_1)->next;
		(*stack_2) = tmp;
		(*stack_2)->next = NULL;
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
