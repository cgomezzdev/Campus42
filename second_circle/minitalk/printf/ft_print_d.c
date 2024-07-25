/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:17:40 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/28 19:44:20 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lnumber(int d)
{
	int	len;

	len = 0;
	if (d < 0)
		len++;
	if (d == 0)
		return (1);
	while (d)
	{
		d = d / 10;
		len++;
	}
	return (len);
}

static int	negative(int d)
{
	if (d < 0 && d != -2147483648)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		d *= -1;
	}
	return (d);
}

int	ft_print_d(int d)
{
	char	num;
	int		len;

	len = lnumber(d);
	d = negative(d);
	if (d == -1)
		return (-1);
	if (d == -2147483648)
		return (write(1, "-2147483648", 11));
	if (d > 9)
	{
		num = d % 10 + '0';
		if (ft_print_d(d / 10) == -1)
			return (-1);
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	if (d <= 9)
	{
		num = d + '0';
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	return (len);
}
