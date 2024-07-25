/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:02:27 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/28 17:46:31 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lnum(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_x(unsigned int n, int type)
{
	char	hexa;
	char	*base;
	int		len;

	len = lnum(n);
	base = "0123456789abcdef";
	if (type == 1)
		base = "0123456789ABCDEF";
	if (n > 15)
	{
		hexa = base[n % 16];
		if (ft_print_x(n / 16, type) == -1)
			return (-1);
		if (write(1, &hexa, 1) == -1)
			return (-1);
	}
	if (n < 16)
	{
		hexa = base[n];
		if (write(1, &hexa, 1) == -1)
			return (-1);
	}
	return (len);
}
