/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:24:23 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 20:01:09 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Anade el nodo 'new' al principio de la lista 'lst'*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;//Primero hacemos que el nuevo nodo apunte al primer nodo de la lista.
	*lst = new;//Luego le decimos que el primero nodo sera igual al nuevo nodo.
}
