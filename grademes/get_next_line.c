/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:38:58 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/02/05 14:55:29 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	int		byte;
	int		i;
	char	c;
	char	*line;

	if(BUFFER_SIZE < 1 || fd < 0)
		return(NULL);
	i = 0;
	line = malloc((10000) * (sizeof(char *)));
	if(!line)
		return(NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		line[i] = c;
		i++;
		if (c == '\n' || EOF)
			break ;
		byte = read(fd, &c, 1);
	}
	if(i == 0 || byte < 0)
	{
		free(line);
		return(NULL);
	}
	line[i] = '\0';
	return (line);
}

/*
int	main(void)
{
	int		fd;
	int		i;
	char	*path;
	char	*line;

	i = -1;
	path = "test.txt";
	fd = open(path, O_RDONLY);
	while (++i < 2)
	{
		line = get_next_line(fd);
		printf("line: %s\n", line);
	}
	return (0);
}*/
