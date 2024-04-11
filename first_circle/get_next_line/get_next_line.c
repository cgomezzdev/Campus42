/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:55 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/11 21:10:10 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_fd(int fd, char *buf, char *rest_of_line)
{
	ssize_t	byte;
	char	*tmp;

	// to read before \n
	// call the function strchar to read still find the character.
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
/*
static char	*ft_cut_line(char *line,char *rest_of_line)
{
	int	end;
	int	start;
	int	len;

	// function to save the substr of the strings before the \n.
	// call the function substr to agroup the strigs.
	start = 0;
	len = 0;
	while (rest_of_lien[len] != '\n')
	{
		len++;
	}
	if (rest_of_line[len] == '\n')
	{
		len += 1;
		line = ft_substr(rest_of_line,start,len);
	}
	else
	rest_of_line= ft_substr(rest_of_line,end,len);
}

static char	*ft_clean_rest(void)
{
	//function to clean and return de rest of the line after the \n.
	//use substr i think/
}
*/
char	*get_next_line(int fd)
{
	static char	*rest_of_line;
	char		*line;
	char		*buf;

	rest_of_line = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (rest_of_line == NULL)
		return (NULL);
	rest_of_line[0] = '\0';
	buf = malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (buf == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_of_line = ft_read_fd(fd, buf, rest_of_line);
	printf("Print rest of line: %s\n", rest_of_line);
	printf("Print line: %s\n", line);
	//	line = ft_cut_line(buf,rest_of_line);
	//	ft_clean_rest();
	if (line == NULL)
		return (NULL);
	return (line);
}
