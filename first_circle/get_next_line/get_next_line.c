/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:55 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/16 14:37:10 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_fd(int fd, char *rest_of_line)
{
	ssize_t	byte;
	char	*tmp;

	byte = 1;
	tmp = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (tmp == NULL)
		return (ft_free(&rest_of_line));
	tmp[0] = '\0';
	while (!ft_strchr(tmp, '\n'))
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte < 0)
		{
			free(tmp);
			return (ft_free(&rest_of_line));
		}
		tmp[byte] = '\0';
		rest_of_line = ft_strjoin(rest_of_line, tmp);
	}
	free(tmp);
	if (byte == -1)
		ft_free(&rest_of_line);
	return (rest_of_line);
}

static char	*ft_cut_line(char *line, char *rest_of_line)
{
	int	start;
	int	len;

	start = 0;
	len = 0;
	if (rest_of_line[0] == '\0')
		return (NULL);
	while (rest_of_line[len] != '\n' && rest_of_line[len] != '\0')
	{
		len++;
	}
	if (rest_of_line[len] == '\n')
		len += 1;
	line = ft_substr(rest_of_line, start, len);
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
	if (rest_of_line[start] == '\0')
	{
		free(rest_of_line);
		return (NULL);
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

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest_of_line = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest_of_line);
		return (NULL);
	}
	line = NULL;
	rest_of_line = ft_read_fd(fd, rest_of_line);
	if (!rest_of_line)
		return (NULL);
	line = ft_cut_line(line, rest_of_line);
	if (!line)
		return (ft_free(&rest_of_line));
	rest_of_line = ft_clean_rest(rest_of_line);
	return (line);
}
