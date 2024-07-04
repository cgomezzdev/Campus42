/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/04 18:23:40 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El servidor debe lanzarse primero y tras esto debe mostrar su PID.
El servidor debe ser capaz de mostrar la string suficientemente rapido.
El servidor debe poder recibir string de distintos cliente consectuviamente sin reiniciarse.
Solo puedes utilizar estas dos signals SIGUSR1 y SIGUSR2.
BONUS
El servidor confirma cada signal recibida mandando una singal al cliente.
Soporta los caracteres Unicode.*/

#include "minitalk.h"

void	handler_sigint(int sig)
{
	printf("signal: %i", sig);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid: %i\n", pid);
	// si recibo señal de sigusr1 ejecuta esta funcion.
	signal(SIGUSR1, handler_sigint);
	while (1)
		pause();
	return (0);
}
/*
comando para mandar signal:

kill(SIGUSR1, 672);//pid = 672*/
