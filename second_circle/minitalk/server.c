/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/21 21:14:57 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El servidor debe lanzarse primero y tras esto debe mostrar su PID.
El servidor debe ser capaz de mostrar la string suficientemente rapido.
El servidor debe poder recibir string de distintos cliente consectuviamente sin reiniciarse.
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

void	ft_putstr(char *s, int len)
{
	write(1, &s, len);
	// write(1, "\n", 1);
}

void	handler_sigint1(int sig)
{
	static int	i = 7;
	static char	c = '\0';
	static char	*str;
	static int	l = 31;
	static int	len = 0;
	int j = 0;

	if (sig == SIGUSR1)
	{
		len = (len | (1 << l));
	}
	l--;
	str = malloc((len + 1) * (sizeof(char)));
	if (str == NULL)
		return ;
	if (sig == SIGUSR1)
	{
		c = (c | (1 << i));
		// write(1, "1\n", 2);
	}
	// else if (sig == 12)
	// write(1, "0\n", 2);
	i--;
	if (i == -1)
	{
		// write(1, &c, 1);
		str[j] = c;
		j++;
		// write(1, &str[0], 1);
		if (str[j] == '\0')
			ft_putstr(str, len);
		write(1, "\n", 1);
		i = 7;
		c = '\0';
	}
}

int	main(void)
{
	pid_t	pid;
	char	*str;

	pid = getpid();
	printf("pid: %i\n", pid);
	// si recibo señal de sigusr1 ejecuta esta funcion.
	signal(SIGUSR2, handler_sigint1);
	signal(SIGUSR1, handler_sigint1);
	while (1)
		pause();
	return (0);
}
/*
comando para mandar signal:

kill(SIGUSR1, 672);//pid = 672*/
