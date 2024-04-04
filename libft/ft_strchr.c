/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:30:30 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/01/22 20:59:48 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;

	i = 0;
	ch = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (ch);
		i++;
		ch++;
	}
	if ((char)c == '\0')
		return (ch);
	return (NULL);
}
