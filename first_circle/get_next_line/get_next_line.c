/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:55 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/09 22:15:12 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_read_fd(int fd,char *buf,)
{
	// to read before \n
	// call the function strchar to read still find the character.
	ssize_t byte;
	char *tmp;
	
	tmp = buf;
	while (ft_strchr(tmp,'\n')== -1)
	{
	 byte = read(fd, tmp, BUFFER_SIZE);
	 if (byte < 0)
		 return (NULL)
	 rest_of_line = ft_strjoin(tmp);
	}
}
/*
static char	*ft_cut_line(char *buf,char *rest)
{
	// function to save the substr of the strings before the \n.
	// call the function substr to agroup the strigs.
}

static char *ft_clean_rest()
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
	
	buf = malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (buf == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_fd(fd, buf);
	printf("Print buff: %s\n",buf);
	printf("Print buff: %s\n",line);
//	line = ft_save_line(buf,rest_of_line);
//	ft_clean_rest();
	if (line == NULL)
		return (NULL);
	return (line);
}
