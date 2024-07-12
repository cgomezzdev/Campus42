/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:35:55 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/12 15:04:16 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *s)
{
	int	num;
	int	i;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') || s[i])
	{
		num = (num * 10) + s[i] - '0';
		i++;
	}
	num *= sign;
	return (num);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		printf("string: %s\n", av[1]);
		printf("string: %i\n", ft_atoi(av[1]));
	}
	return (0);
}
