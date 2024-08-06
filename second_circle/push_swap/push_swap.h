/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:47 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/06 22:10:43 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
int					ft_checkrepeat(t_list *lst);
void				ft_printlst(t_list **lst);
int					check_dupe(t_list *lst, int num);

#endif
