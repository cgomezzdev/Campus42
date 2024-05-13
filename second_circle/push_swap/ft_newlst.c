/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:10:54 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/13 21:24:08 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlst(int num)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst = NULL)
		return (NULL);
	lst->content = num;
	lst->next = NULL;
	return (lst);
}
