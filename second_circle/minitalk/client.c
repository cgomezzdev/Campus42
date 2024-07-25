/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:13:43 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/25 20:45:37 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	inttbits(int pid, int len)
{
	static int	i = 31;

	while (i > -1)
	{
		if (len & (1 << i))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(150);
		i--;
	}
}

void	strtbits(int pid, char *s)
{
	static int	i = 7;

	while (*s)
	{
		i = 7;
		while (i > -1)
		{
			if (*s & (1 << i))
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(150);
			i--;
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	int	pids;

	if (ac != 3)
		return (0);
	pids = atoi(av[1]);
	ft_printf("Pid server: %i\n", pids);
	inttbits(pids, ft_strlen(av[2]));
	strtbits(pids, av[2]);
	return (0);
}
