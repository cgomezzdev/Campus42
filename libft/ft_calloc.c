/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:43:38 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/02/07 20:47:31 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*r;

	i = 0;
	r = malloc(count * size);
	if (r == NULL)
		return (NULL);
	while (i < count * size)
	{
		r[i] = 0;
		i++;
	}
	return (r);
}
