/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:28:21 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/02 23:38:03 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	alpha_mirror(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = ('Z' - s[i] + 'A');
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = ('z' - s[i] + 'a');
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		alpha_mirror(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
