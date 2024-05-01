/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:12:59 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 20:43:56 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cuenta el numero de nodos de una lista*/

int	ft_lstsize(t_list *lst)
{
	int	lenlst;

	lenlst = 0;
	while (lst)
	{
		lst = lst->next;//Le decimos que el nodo actual es igual al siguiente nodo.
		lenlst++;//vamos sumando hasta que el ultimo nodo encuentre el NULL.
	}
	return (lenlst);//Retornamos el numero
}
