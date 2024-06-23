/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:47:15 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/23 19:51:08 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	off_set;

	off_set = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + off_set) = color;
}

int	main(int ac, char *av[])
{
	t_fractol	fract;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		printf("All good!\n");
		fract.name = av[1];
		fractol_init(&fract);
		fractol_render(&fract);
		mlx_loop(fract.mlx_connection);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
