/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dupe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:02:17 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/06 22:08:31 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
