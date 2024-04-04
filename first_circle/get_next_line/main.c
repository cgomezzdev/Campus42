/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:03:01 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/02 19:13:20 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("/Users/cgomez-z/cursus/first_circle/get_next_line/test",
			O_RDONLY);
	if (fd < 0)
		printf("Error to open file");
	else
		get_next_line(fd);
	return (0);
}
