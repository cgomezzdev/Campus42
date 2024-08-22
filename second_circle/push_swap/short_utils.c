/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:22:13 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/23 01:22:17 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_list **stack_a)
{
	t_list	*tmp;
	int		ref;

	tmp = (*stack_a);
	ref = tmp->content;
	ft_printlst(&tmp);
	while (tmp)
	{
		if (ref > tmp->content)
			ref = tmp->content;
		tmp = tmp->next;
	}
	while ((*stack_a))
	{
		if ((*stack_a)->content == ref)
			(*stack_a)->index += 1;
		(*stack_a) = (*stack_a)->next;
	}
	printf("Find min:");
	ft_printlst(stack_a);
}

void	putmin_top(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	find_min(&tmp);
	printf("min to top:");
	ft_printlst(stack_a);
	while ((*stack_a)->index != 0)
	{
		printf("A");
		ra(stack_a);
	}
}
