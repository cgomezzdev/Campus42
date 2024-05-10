/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:05:46 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/02 22:26:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	rev_print(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	while (--len >= 0)
	{
		ft_putchar(s[len]);
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		rev_print(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
