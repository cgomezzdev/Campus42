/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:23:49 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 19:56:55 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Crea un nuevo nodo utilizando malloc().La variable miembro 'content' se inicializa con el contenido del parametro 'content'. La variable 'next',con NULL.
 Valor devuelto: el nuevo nodo.*/

t_list	*ft_lstnew(void *content)
{
	//Creamos el nuevo nodo y lo hacemos un malloc.
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;//meteremos el contenido que nos pasan en el contenido de la lista.
	list->next = NULL;//La siguiente direccion de memoria apuntara a NULL dado que las listas acaban en NULL.
	return (list);//Por ultimo retornamos el node.
}
