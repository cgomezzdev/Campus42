/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:11:11 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 21:18:38 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Toma como parametro un nodo 'lst' y libera la memoria del contenido utilizando la uncion 'del' dada como parametro, ademas de liverar el nodo.
 La memoria de 'next' no debe liberarse. */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);//A la funcion del le pasamos como parametro el contenido de la lista.
	free(lst);//Liberamos la memoria del nodo.
}
