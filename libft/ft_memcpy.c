/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:46:46 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/01/19 19:18:39 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstp;
	unsigned const char	*srcp;

	srcp = (unsigned char *)src;
	dstp = (unsigned char *)dst;
	while (dst == src || (dst == 0 && src == 0))
	{
		return (dst);
	}
	i = 0;
	while (i < n)
	{
		dstp[i] = srcp[i];
		i++;
	}
	return (dst);
}
