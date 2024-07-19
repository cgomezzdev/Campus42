/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:45 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/19 15:50:02 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*aux;
	t_list	*del;
	t_list	*prev;

	aux = *begin_list;
	prev = NULL;
	while (aux)
	{
		if ((cmp)(aux->data, data_ref) == 0)
		{
			del = aux;
			if (prev == NULL)
				*begin_list = aux->next;
			else
				prev->next = aux->next;
			aux = aux->next;
			free(del);
		}
		else
		{
			prev = aux;
			aux = aux->next;
		}
	}
}
