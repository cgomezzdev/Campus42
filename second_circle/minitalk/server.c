/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/03 19:26:25 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
