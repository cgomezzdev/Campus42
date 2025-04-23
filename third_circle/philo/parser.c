/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/23 03:15:55 by cgomez-z         ###   ########.fr       */
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

	i = 1;
	if (ac > 4 && ac < 7)
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
