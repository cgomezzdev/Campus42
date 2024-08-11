/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:53:25 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/11 20:22:50 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_newlst(int num)
{
        t_list  *lst;

        lst = malloc(sizeof(t_list));
        if (lst == NULL)
                return (NULL);
        lst->content = num;
        lst->next = NULL;
        return (lst);
}

int     ft_checkrepeat(t_list *lst)
{
        t_list  *tmp1;
        t_list  *tmp2;

        tmp1 = lst;
        while (tmp1->next != NULL)
        {
                tmp2 = tmp1->next;
                while (tmp2)
                {
                        if (tmp1->content == tmp2->content)
                                return (-1);
                        tmp2 = tmp2->next;
                }
                tmp1 = tmp1->next;
        }
        return (0);
}

t_list  *ft_last_lst(t_list *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next != NULL)
        {
                lst = lst->next;
        }
        return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *last;

        if (*lst == NULL)
        {
                *lst = new;
                return ;
        }
        last = ft_last_lst(*lst);
		printf("last:%d\n",last->content);
        last->next = new;
}
