/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:13:43 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/25 02:25:31 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El cliente tomara como parametros (server PID,la string que deberia mandarse.
El cliente debe comunicar la string pasada como parametro al servidor
Una vez la string se haya recibido, el servidor debe motrala.
Solo puedes utilizar estas dos signals SIGUSR1 y SIGUSR2.
BONUS
El servidor confirma cada signal recibida mandando una singal al cliente.
Soporta los caracteres Unicode.*/

//#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
			// write(1, "1\n", 2);
		}
		else
		{
			kill(pid, SIGUSR2);
			// write(1, "0\n", 2);
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
				kill(pid, SIGUSR1); // Campus signal=10.
									// write(1, "1\n", 2);
			}
			else
			{
				kill(pid, SIGUSR2); // Campus signal=12.
									// write(1, "0\n", 2);
			}
			usleep(150);
			i--;
		}
		// write(1, s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	int		pids;

	if (ac != 3)
		return (0);
	pids = atoi(av[1]);
	printf("Pid server: %i\n", pids);
	inttbits(pids, ft_strlen(av[2]));
	strtbits(pids, av[2]);
	// while (1)
	// pause();
	return (0);
}
