/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:21:22 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/23 03:14:01 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	numlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	printf("lenNUM: %d\n", i);
	return (i);
}

char	*ft_itoa(int num)
{
	char	*s;
	int		len;

	len = numlen(num);
	s = malloc((len +1) * (sizeof(char)));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	len--;
	while (len >= 0 && num > 0)
	{
		s[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (s);
}

int	main(void)
{
	int		num;
	char	*s;

	num = 19;
	printf("Num: %d\n", num);
	s = ft_itoa(num);
	printf("Num: %s", s);
	return (0);
}
