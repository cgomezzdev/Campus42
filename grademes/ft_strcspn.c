/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:48:17 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/02 20:56:30 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	main(void)
{
	char	string[20] = "Hola como estas";
	char	*substring;

	substring = "axle";
	printf("The first %zu characters in the string \"%s\" "
			"are not in the string \"%s\" \n",
			strcspn(string, substring),
			string,
			substring);
	printf("The first %zu characters in the string \"%s\" "
			"are not in the string \"%s\" \n",
			ft_strcspn(string, substring),
			string,
			substring);
}
