/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/25 21:21:50 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

char	*g_str;

char	*get_str(int len)
{
	g_str = malloc((len + 1) * (sizeof(char)));
	if (g_str == NULL)
		exit(1);
	return (g_str);
}

void	final_put(int *len, int *j, int *l)
{
	g_str[*len] = '\0';
	ft_printf("%s\n", g_str);
	free(g_str);
	*j = 0;
	*len = 0;
	*l = 31;
}

void	handler_sigint1(int sig)
{
	static int	i = 7;
	static char	c = '\0';
	static int	l = 31;
	static int	len = 0;
	static int	j = 0;

	if (sig == SIGUSR1 && l > -1)
		len = (len | (1 << l));
	l--;
	if (l == -1)
		g_str = get_str(len);
	if (l < -1)
	{
		if (sig == SIGUSR1)
			c = (c | (1 << i));
		i--;
		if (i == -1)
		{
			g_str[j++] = c;
			i = 7;
			c = 0;
		}
	}
	if (j == len && l < -1)
		final_put(&len, &j, &l);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid: %i\n", pid);
	signal(SIGUSR2, handler_sigint1);
	signal(SIGUSR1, handler_sigint1);
	while (1)
		pause();
	return (0);
}
