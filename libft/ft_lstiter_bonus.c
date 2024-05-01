/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:20:15 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 21:27:04 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Itera la lista 'lst' y aplica la funcion 'f' en el contenido de cada nodo.*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)//Mientras exista la lista.
	{
		f(lst->content);//Aplicamos la funcion 'f' al contenido del nodo.
		lst = lst->next;//Igualamos el nodo al siguiente.
	}
}
