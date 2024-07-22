/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/22 22:06:43 by cgomez-z         ###   ########.fr       */
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

char	*str;

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
	printf("putstr %s len %d\n", str, len);
	write(1, s, len + 1);
	write(1, "\n", 1);
	// write(1, "\n", 1);
}
/*
int	get_len(int sig)
{
}

char	*get_str(int sig)
{
}

if (bits < 32)
	get_len;
else
	get_str;
if (byte == '\0')
{
	bits == 0;
	ft_putstr(string);
	free(string);
}
	*/

void	handler_sigint1(int sig)
{
	static int	i = 7;
	static char	c = '\0';
	static int	l = 31;
	static int	len = 0;
	static int	j = 0;

	if (sig == SIGUSR1 && l > -1)
	{
		len = (len | (1 << l));
	}
	l--;
	if (l == -1)
	{
		str = malloc((len + 1) * (sizeof(char)));
		if (str == NULL)
			return ;
	}
	if (l < -1)
	{
		if (sig == SIGUSR1)
		{
			c = (c | (1 << i));
			// write(1, "1\n", 2);
		}
		i--;
		if (i == -1)
		{
			str[j] = c;
			// write(1, &c, 1);
			// write(1, &str[j], 1);
			j++;
			i = 7;
			c = 0;
		}
	}
	if (j == len && l < -1)
	{
		str[len] = '\0';
		ft_putstr(str, len);
		free(str);
		j = 0;
		len = 0;
		l = 31;
	}
}

int	main(void)
{
	pid_t	pid;

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
