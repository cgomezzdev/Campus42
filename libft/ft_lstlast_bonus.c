/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:23:11 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 20:59:04 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*Devuelve el ultimo nodo de la lista*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)//Mientras el siguiente no sea NULL entrea en el bucle
	{
		lst = lst->next;//El nodo es igual al siguiente nodo.
	}
	return (lst);//Retornamos el ultimo nodo.
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*element1;
	t_list	*element2;
	t_list	*element3;
	t_list	*last;

	head = NULL;
	element1 = ft_lstnew("Nodo1");
	element2 = ft_lstnew("Nodo2");
	element3 = ft_lstnew("Nodo3");
	head = element1;
	element1->next = element2;
	element2->next = element3;
	element3->next = NULL;
	last = ft_lstlast(head);
	if (last != NULL)
		printf("%s \n", (char *)(last->content));
	else 
		printf("lst empty");
}*/
