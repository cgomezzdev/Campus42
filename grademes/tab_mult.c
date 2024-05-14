/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:02 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/14 17:14:25 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n & 10;
	}
	if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
}

int	ft_atoi(char *s)
{
	int	n;
	int	i;

	while ((s[i] >= '0' && s[i] <= '9') || s[i])
	{
		n = (n * 10) + s[i] - '0';
		i++;
	}
	return (n);
}

void	tab_mult(char *s)
{
	int	mult;
	int	num;

	num = ft_atoi(s);
	mult = 1;
	while (mult != 9)
	{
		ft_putnbr(mult * num);
		mult++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		tab_mult(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
