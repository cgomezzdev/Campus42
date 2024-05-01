/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:29:19 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/01 22:05:47 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. Crea una lista resultante de la aplicación correcta y sucesiva de la función
’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el contenido de un nodo, si hace falta.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;//Var pra gurdar la direccion de memoria de una lista la nueva lista.
	t_list	*node;//Creamos el primer nodo.
	void	*cont;//Como no sabemos que contendra al haber apliacado la funcion 'f' sera tipo void.

	newlst = NULL;//Igualamos la nueva lista a NULL porque actualmente esta vacia.
	while (lst)//Mientras la lista actual exista.
	{
		cont = f(lst->content);//El nuevo contenido sera el contenido del primer nodo pero aplicando la funcion 'f'.
		node = ft_lstnew(cont);//El primer nodo sera igual a la funcion para crear un nuevo nodo con el contenido de este.
		if (node == NULL)//Si el nodo falla
		{
			ft_lstclear(&newlst, del);//Limpiaremos la nueva lista y le pasaremos la funcion 'del' a esta.
			del(cont);//Borraremos el contenido.
			return (NULL);//Retornamos NULL.
		}
		ft_lstadd_back(&newlst, node);//Si no es el caso anadimos el nuevo nodo al final de la nueva lista.
		lst = lst->next;//igualamos el nodo al siguiente.
	}
	return (newlst);//Retronamos la nueva lista con el contenido modificado por la funcion 'f'.
}
