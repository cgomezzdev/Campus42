/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:13:43 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/13 19:19:15 by cgomez-z         ###   ########.fr       */
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

void	strtbits(int pid, char *s)
{
	static int	i = 7;
	static int	c = 0;

	while (*s)
	{
		i = 7;
		while (i > -1)
		{
			if (*s & (1 << i))
			{
				kill(pid, SIGUSR1); // Campus signal=10.
				write(1, "1\n", 2);
				usleep(100);
			}
			else
			{
				kill(pid, SIGUSR2); // Campus signal=12.
				write(1, "0\n", 2);
				usleep(100);
			}
			i--;
		}
		write(1, &s, 1);
		s++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	// char	*c;
	pid = atoi(av[1]);
	// c = av[2];
	strtbits(pid, "hola");
	printf("%i\n", pid);
	// kill(pid, SIGUSR1);
	return (0);
}
