/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_str_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:58:01 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/02 19:22:59 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && n > 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		if (write(fd, s + i++, 1) == -1)
			return ;
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	check_double(char *s)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (f)
				return (1);
			f = 1;
			++i;
		}
		if (!ft_isdigit(s[i]))
			return (1);
		if (s[i])
			i++;
	}
	if (s[i])
		return (1);
	return (0);
}
