/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/22 18:41:21 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	parser(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 3 && ac < 6)
	{
		while (av[i])
		{
			if (is_num(av[i]) == 1)
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (parser(ac, av) == 0)
		printf("todo bien");
	else
		printf("todo mal");
	return (0);
}
