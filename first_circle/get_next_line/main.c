/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:03:01 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/10 21:14:26 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open(argv[1], O_RDONLY);
	// if (fd < 0)
	//	printf("Error to open file");
	while (++i < 2)
	{
		line = get_next_line(fd);
		printf("Line : %s \n", line);
	}
	return (0);
}
