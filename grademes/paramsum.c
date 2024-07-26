/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:43:35 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/26 13:48:41 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n > 9 )
	{
		ft_putnbr(n/10);
		n = n % 10;
	}
	if (n < 10)
	{
		n = n + '0';
		write(1,&n,1);
	}
}

int	main(int ac, char *av[])
{
	(void)av;
	ft_putnbr(ac-1);
	write(1, "\n", 1);
	return (0);
}
