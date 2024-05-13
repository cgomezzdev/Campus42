/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:06:20 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/10 01:11:53 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_min(int start, int end)
{
	if (start < end)
		return (start);
	else
		return (end);
}

int	ft_max(int start, int end)
{
	if (start > end)
		return (start);
	else
		return (end);
}

int	*ft_range(int start, int end)
{
	int	*array;
	int	i;
	int	min;
	int	max;

	i = 0;
	min = ft_min(start, end);
	max = ft_max(start, end);
	array = malloc((max - min + 1) * (sizeof(int)));
	if (array == NULL)
		return (NULL);
	if (start > end)
	{
		while (start >= end)
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	else
	{
		while (end >= start)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	return (array);
}
/*
int	main(void)
{
	int	start;
	int	end;
	int	*ar;
	int	i;
	int min;
	int max;

	start = -11;
	end = 3;
	min = ft_min(start,end);
	max = ft_max(start,end);
	ar = ft_range(start, end);
	i = 0;
	while (i <= max - min)
	{
		printf("NUM %d\n", ar[i]);
		i++;
	}
	return (0);
}*/
