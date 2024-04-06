/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:55 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/06 19:28:30 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_read_fd(int fd,rest)
{
// to read before \n
// call the function strchar to read still find the character.
}

void ft_save_line()
{
//function to save the strjoin of the strings before the \n.
//call the function strjoin to agroup the strigs.
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_fd(fd,rest);
	ft_save_line();
	ft_clean_rest();
	if (line == NULL)
		return (NULL);
	return (line);
}
