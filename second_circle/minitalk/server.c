/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:38:24 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/25 20:49:09 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>

char	*g_str;

void	ft_putstr(int len)
{
	write(1, str, len + 1);
	write(1, "\n", 1);
}

char	*get_str(int len)
{
	char	*str;

	str = malloc((len + 1) * (sizeof(char)));
	if (str == NULL)
		exit(1);
	return (str);
}

void	final_put(int *len, int *j, int *l)
{
	str[*len] = '\0';
	ft_putstr(*len);
	free(str);
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
		str = get_str(len);
	if (l < -1)
	{
		if (sig == SIGUSR1)
			c = (c | (1 << i));
		i--;
		if (i == -1)
		{
			str[j++] = c;
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
		;
	return (0);
}
