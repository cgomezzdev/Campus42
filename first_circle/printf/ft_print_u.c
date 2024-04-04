/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:04:47 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/26 21:34:34 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lnum(unsigned int u)
{
	int	len;

	if (u == 0)
		return (1);
	len = 0;
	while (u)
	{
		u = u / 10;
		len++;
	}
	return (len);
}

int	ft_print_u(unsigned int u)
{
	char	num;
	int		len;

	len = lnum(u);
	if (u > 9)
	{
		num = u % 10 + '0';
		if (ft_print_u(u / 10) == -1)
			return (-1);
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	if (u <= 9)
	{
		num = u + '0';
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	return (len);
}
