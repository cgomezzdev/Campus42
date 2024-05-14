/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:42:05 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/14 16:28:21 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	first_letter(char *str)
{
	int	fl;

	fl = ft_strlen(str) - 1;
	while (str[fl] == ' ' || str[fl] == '\t')
		fl--;
	while (str[fl] != ' ' && str[fl] != '\t')
	{
		fl--;
	}
	return (fl);
}

void	last_word(char *str)
{
	int	i;

	i = first_letter(str) + 1;
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		last_word(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
