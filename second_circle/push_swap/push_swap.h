/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:47 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/21 21:29:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				content;
}					t_list;

int					ft_isdigit(int c);
int long			ft_atoi(char *str, int *flagr);
t_list				*ft_newlst(int num);
t_list				*ft_last_lst(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(int n));

#endif
