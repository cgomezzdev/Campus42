/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:04:51 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/01 19:18:15 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	printf("List: ");
	while (tmp != NULL)
	{
		printf("%i[%i] ", tmp->content,tmp->index);
		tmp = (tmp)->next;
	}
	printf("done\n");
}
