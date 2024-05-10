/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:34:47 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/06 14:19:22 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	int		cmp1;
	int		cmp2;
	char	*s1;
	char	*s2;

	s1 = strdup("hola");
	s2 = strdup("hola1");
	cmp1 = strcmp(s1, s2);
	cmp2 = ft_strcmp(s1, s2);
	printf("Original:%i\n", cmp1);
	printf("Mine:%i\n", cmp2);
	return (0);
}
