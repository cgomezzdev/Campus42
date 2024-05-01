/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:54:13 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 21:05:21 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Anade el nodo 'new' al final de la lista 'lst'*/

void	ft_lstadd_back(t_list **lst, t_list *new)//Puntero al primer nodo de una lista, puntero a un nodo que anadir a la lista.
{
	t_list	*last;//Puntero que apuntal primer nodo

	if (!(*lst))//Si el nodo no existe
	{
		*lst = new;//El nodo acutal es igual al nuevo nodo porque la lista esta vacia.
		return ;
	}
	last = ft_lstlast(*lst);//last es igual al ultimo nodo.
	last->next = new;//Last apunta al nuevo nodo.
}
