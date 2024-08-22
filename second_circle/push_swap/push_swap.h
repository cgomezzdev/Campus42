/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:47 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/08/15 16:05:29 by cgomez-z         ###   ########.fr       */
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
	int				index;
}					t_list;

int					ft_isdigit(int c);
int long			ft_atoi(char *str, int *flagr);
t_list				*ft_newlst(int num);
t_list				*ft_last_lst(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				free_lst(t_list *stack);
void				ft_printlst(t_list **lst);
int					check_dupe(t_list *lst, int num);
int					lst_size(t_list *lst);
int					lst_sorted(t_list *stack_a);

/*chekcs*/
int				checker_digits(char *str);
int				arg_checker(char **av, int flagr);

/*moves*/

void				find_min(t_list **stack_a);
void				putmin_top(t_list **stack_a);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				push(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				ra(t_list **stack_a);
void				rra(t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				ft_sort2(t_list **stack_a);
void				ft_sort3(t_list **stack_a);
void				ft_sort4(t_list **stack_a, t_list **stack_b);
void				ft_sort5(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b);

#endif
