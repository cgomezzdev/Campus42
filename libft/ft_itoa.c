/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:23:17 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/02/07 20:09:43 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		len = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_special_cases(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (0);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		slen;

	i = 0;
	if (n == -2147483648 || n == 0)
		return (ft_special_cases(n));
	slen = ft_intlen(n);
	s = malloc((slen + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	else if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	s[slen] = '\0';
	while (n)
	{
		slen--;
		i = n % 10;
		n = n / 10;
		s[slen] = i + '0';
	}
	return (s);
}
