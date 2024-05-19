/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:21:37 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/19 18:47:10 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int long	ft_atoi(char *str, int *flagr)
{
	int long	num;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = (num * 10) + str[i] - '0';
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			*flagr = 1;
		i++;
	}
	num = num * sign;
	return (num);
}
