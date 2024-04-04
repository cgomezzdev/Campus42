/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:45 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/17 19:32:47 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	formats(int c, va_list args);
int	ft_print_c(int c);
int	ft_print_s(char *str);
int	ft_print_p(unsigned long p, int in);
int	ft_print_d(int d);
int	ft_print_i(int i);
int	ft_print_u(unsigned int i);
int	ft_print_x(unsigned int i, int type);

#endif
