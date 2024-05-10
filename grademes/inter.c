/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:57:38 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/07 02:53:27 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writer(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			write(1, &c, 1);
			return ;
		}
		i++;
	}
}

int	check1(char *s, char c, int p)
{
	int	i;

	i = 0;
	while (i < p)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		if (!(check1(s1, s1[i], i)))
		{
			writer(s2, s1[i]);
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
