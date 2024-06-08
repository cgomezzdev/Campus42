/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:47:15 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/08 19:42:06 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char *av[])
{
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
		&& !ft_strncmp(av[1], "julia", 5)))
	{
		printf("All good!\n");
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
