/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:47 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/08 21:37:59 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int					ft_isdigit(int c);
int long			ft_atoi(const char *str,int *flagr);

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

#endif