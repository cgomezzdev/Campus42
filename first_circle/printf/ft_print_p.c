/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:30:10 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/26 19:24:05 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long p, int in)
{
	char	ptr;
	char	*base;
	int		len;

	len = 0;
	if (in == 0)
	{
		if (ft_print_s("0x") == -1)
			return (-1);
		len = 2;
	}
	base = "0123456789abcdef";
	if (p > 15)
	{
		ptr = base[p % 16];
		len += ft_print_p(p / 16, 1);
		len += write(1, &ptr, 1);
	}
	if (p < 16)
	{
		ptr = base[p];
		len += write(1, &ptr, 1);
	}
	return (len);
}
