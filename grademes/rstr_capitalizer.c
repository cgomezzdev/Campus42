/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:03:05 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/17 02:23:13 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_next(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	rstr_capitalizer(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z' && !check_next(s[i + 1]))
			ft_putchar(s[i] + 32);
		else if (s[i] >= 'a' && s[i] <= 'z' && check_next(s[i + 1]))
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
			rstr_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
