/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:24:42 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/30 18:08:46 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
}

void	fizzbuzz(int n)
{
	int	i;

	i = 1;
	while (i != n + 1)
	{
		if (i % 3 == 0)
		{
			write(1, "fizz", 4);
		}
		if (i % 5 == 0)
		{
			write(1, "buzz", 4);
		}
		if (i % 3 != 0 && i % 5 != 0)
		{
			ft_putnbr(i);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	fizzbuzz(50);
	return (0);
}
