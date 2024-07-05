/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:38:01 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/13 17:02:18 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// This function is to know how much we need to print a letter.
int	letter_count(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 1);
	}
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	return (1);
}
//This function is to print the chars of the string.
void	repeat_alpha(char *s)
{
	int	i;
	int	rep;

	i = 0;
	while (s[i])
	{
		rep = letter_count(s[i]);
		while (rep > 0)
		{
			write(1, &s[i], 1);
			rep--;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
