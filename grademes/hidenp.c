/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:02:35 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/09/04 02:24:18 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[j] && s1[i])
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int ac, char *av[])
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
