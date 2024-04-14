/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:55 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/14 21:57:41 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_fd(int fd, char *rest_of_line)
{
	ssize_t	byte;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	while (ft_strchr(tmp, '\n') == -1)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte == 0)
			break ;
		printf("pre-check\n");
		if (byte < 0)
			return (NULL);
		printf("pre-join\n");
		rest_of_line = ft_strjoin(rest_of_line, tmp);
		printf("POST JOIN _%s_ tmp _%s_\n", rest_of_line, tmp);
	}
	free(tmp);
	return (rest_of_line);
}

static char	*ft_cut_line(char *line, char *rest_of_line)
{
	int	start;
	int	len;

	start = 0;
	len = 0;
	while (rest_of_line[len] != '\n' && rest_of_line[len] != '\0')
	{
		len++;
	}
	if (rest_of_line[len] == '\n')
	{
		len += 1;
		line = ft_substr(rest_of_line, start, len);
	}
	return (line);
}

static char	*ft_clean_rest(char *rest_of_line)
{
	char	*new_rest;
	int		start;
	int		len;

	start = 0;
	while (rest_of_line[start] != '\n' && rest_of_line[start] != '\0')
	{
		start++;
	}
	if (rest_of_line[start] == '\n')
		start++;
	len = 0;
	while (rest_of_line[start + len] != '\0')
	{
		len++;
	}
	new_rest = ft_substr(rest_of_line, start, len);
	free(rest_of_line);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest_of_line;
	char		*line = NULL;

	rest_of_line = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (rest_of_line == NULL)
		return (NULL);
	rest_of_line[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_of_line = ft_read_fd(fd, rest_of_line);
	if (!rest_of_line)
		return (NULL);
	printf("Print rest of line: %s\n", rest_of_line);
	printf("Print line: %s\n", line);
	line = ft_cut_line(line, rest_of_line);
	if (!line)
		return (NULL);
	rest_of_line = ft_clean_rest(rest_of_line);
	printf("Preint new rest of line: %s\n", rest_of_line);
	return (line);
}
