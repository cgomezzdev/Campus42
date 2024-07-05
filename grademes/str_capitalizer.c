/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:49:52 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/31 13:21:11 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_before(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	str_capitalizer(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z' && !check_before(s[i - 1]))
			ft_putchar(s[i] + 32);
		else if (s[i] >= 'a' && s[i] <= 'z' && check_before(s[i - 1]))
			ft_putchar(s[i] - 32);
		else
			ft_putchar(s[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
