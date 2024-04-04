/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:54:31 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/28 19:53:53 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lnum(int i)
{
	int	len;

	len = 0;
	if (i < 0)
		len++;
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

static int	negative(int i)
{
	if (i < 0 && i != -2147483648)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		i *= -1;
	}
	return (i);
}

int	ft_print_i(int i)
{
	char	num;
	int		len;

	len = lnum(i);
	i = negative(i);
	if (i == -1)
		return (-1);
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i > 9)
	{
		num = i % 10 + '0';
		if (ft_print_i(i / 10) == -1)
			return (-1);
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	if (i <= 9)
	{
		num = i + '0';
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	return (len);
}
