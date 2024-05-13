/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:49:58 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/09 22:03:12 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s1)
{
	int	i;
	int	cap;
	int	total;

	i = 0;
	cap = 0;
	total = 0;
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			cap++;
		i++;
	}
	total = i + cap;
	return (total);
}

void	print_s(char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		write(1, &s2[i], 1);
		i++;
	}
}

void	*camel_to_snake(char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	s2 = malloc(ft_strlen(s1 + 1) * (sizeof(char)));
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			s2[j] = '_';
			j++;
			s2[j] = s1[i] + 32;
		}
		else
		{
			s2[j] = s1[i];
		}
		i++;
		j++;
	}
	print_s(s2);
	free(s2);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(1, "\n", 1);
	return (0);
}
