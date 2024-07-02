/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_atod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:42:25 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/29 18:53:57 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	get_decimals(char *s)
{
	int		i;
	double	d;
	double	pow;

	i = 0;
	d = 0;
	pow = 1;
	if (s[i] == '.')
		i++;
	while ((s[i] >= '0' && s[i] <= '9'))
	{
		pow /= 10;
		d += (s[i] - '0') * pow;
		i++;
	}
	return (d);
}

double	ft_atod(char *s)
{
	double	d;
	int		u;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	u = 0;
	d = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		u = (u * 10) + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		d = get_decimals(&s[i]);
	return ((u + d) * sign);
}
