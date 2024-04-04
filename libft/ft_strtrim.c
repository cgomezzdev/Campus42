/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:48:06 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/02/08 20:40:09 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t;
	int		i;
	int		j;

	if (!s1 || !set)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1);
	while (i < (int)ft_strlen(s1) && ft_strchr(set, s1[i]))
		i++;
	while (j - 1 > i && ft_strchr(set, s1[j - 1]))
		j--;
	return (t = ft_substr(s1, i, j - i));
}
