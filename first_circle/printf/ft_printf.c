/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:37:01 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/28 21:18:50 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_all(char const *str, va_list args)
{
	int	i;
	int	len;
	int	f;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			f = formats(str[++i], args);
			if (f == -1)
				return (-1);
			len += f;
		}
		else
		{
			if (ft_print_c(str[i]) == -1)
				return (-1);
			len++;
		}
		if (str[i])
			i++;
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = ft_print_all(str, args);
	va_end(args);
	return (len);
}
