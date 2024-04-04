/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:06:33 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/02/07 20:15:02 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dstp;
	const unsigned char	*srcp;

	dstp = (unsigned char *)dst;
	srcp = (const unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	if (src < dst)
	{
		while (len-- > 0)
			dstp[len] = srcp[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dstp[i] = srcp[i];
			i++;
		}
	}
	return (dst);
}
