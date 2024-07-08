/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/08 20:26:26 by cgomez-z         ###   ########.fr       */
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
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(1,&s,i);
}

void	handler_sigint1(int sig)
{
//	static int i = 0;
	if (sig == 10)
		write(1,"0\n",2);
	else if (sig == 12)
		write(1,"1\n",2);
	//ft_putstr("it works");
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
