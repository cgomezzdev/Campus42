/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/02 01:00:54 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/
void	handler_sigint(int sig)
{
	printf("signal: %i", sig);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid: %i", pid);
	//si recibo señal de sigusr1 ejecuta esta funcion.
	signal(SIGUSR1, handle_sigint);
	sleep(10);
	//while (1)
	//	pause();
	return (0);
}

comando para mandar signal:

kill(SIGUSR1, 672);//pid = 672
