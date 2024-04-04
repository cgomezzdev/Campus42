/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:21:30 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/26 20:36:59 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats(int c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_c(va_arg(args, int));
	else if (c == 's')
		len = ft_print_s(va_arg(args, char *));
	else if (c == 'p')
		len = ft_print_p(va_arg(args, unsigned long), 0);
	else if (c == 'd')
		len = ft_print_d(va_arg(args, int));
	else if (c == 'i')
		len = ft_print_i(va_arg(args, int));
	else if (c == 'u')
		len = ft_print_u(va_arg(args, int));
	else if (c == 'x')
		len = ft_print_x(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		len = ft_print_x(va_arg(args, unsigned int), 1);
	else if (c == '%')
		len = ft_print_c(c);
	return (len);
}
