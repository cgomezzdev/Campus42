\/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:34:50 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/10/23 18:49:20 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include "inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	int i;
	t_list *my_env;

	my_env = NULL;
    i = 0;
	while (1)
	{
		readline("minishell>");
		if (!line)
			break ;
		printf("%s\n", line);
		my_env->name = ft_substr(env[0],0,ft_strchr(env[0],'=') - env[0]);
		my_env->value = ft_substr(ft_strchr(env[0],'='), 1, ft_strlen(strchr(env[0], "=") + 1));
		free(line);
	}
	return (0);
}
