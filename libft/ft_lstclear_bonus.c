/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:46:22 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 21:25:07 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Elimina y livera el nodo 'lst' dado y todos los consecutivos de ese nodo, utilizando la funcion 'del' y free.
 Al final, el puntero de la lista debe ser NULL.*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;//Creamos un temporal para guardar la direccion del siguiente nodo
	t_list	*aux;//Creamos un auxiliar para darle el valor del nodo acutal

	aux = *lst;//Igualamos el auxilar a la lista.
	while (aux)//Mientras la lista extitsa.
	{
		tmp = aux->next;//Igualamos el tmp al siguiente nodo.
		del(aux->content);//Pasamos la funcion de delte el contenido del nodo acutal.
		free(aux);//Liberamos el nodo.
		aux = tmp;//Igualamos el nodo actual al siguiente.
	}
	*lst = NULL;//Iugalamos el nodo a NUll porque al final de unsa lista debe ser NULL.
}
