/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:47:15 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/02 18:48:08 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	off_set;

	off_set = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + off_set) = color;
}

static void	instructions(void)
{
	ft_putstr_fd("You can move it with the arrows\n", 1);
	ft_putstr_fd("You can zoom with the mouse scroll\n", 1);
	ft_putstr_fd("You can add 10 iterations with the left click\n", 1);
	ft_putstr_fd("You can take 10 iterations with the right click\n", 1);
	ft_putstr_fd("You can reset it with the space key\n", 1);
	ft_putstr_fd("You can close it with the escape key ", 1);
	ft_putstr_fd("or the X on the window\n", 1);
}

static int	mandelbrot(t_fractol fract)
{
	ft_putstr_fd("All good!\n", 1);
	instructions();
	if (fractol_init(&fract))
		return (1);
	fractol_render(&fract);
	mlx_loop(fract.mlx_connection);
	return (0);
}

static int	julia(char *av[], t_fractol fract)
{
	if (!check_double(av[2]) && !check_double(av[3]))
	{
		fract.julia_x = ft_atod(av[2]);
		fract.julia_y = ft_atod(av[3]);
		if (fract.julia_x * fract.julia_x > 4 || fract.julia_y
			* fract.julia_y > 4)
		{
			ft_putstr_fd("Julia values must be between 2 and -2\n", 2);
			return (1);
		}
		ft_putstr_fd("All good!\n", 1);
		instructions();
		if (fractol_init(&fract))
			return (1);
		fractol_render(&fract);
		mlx_loop(fract.mlx_connection);
	}
	else
		ft_putstr_fd("The arguments after julia are not doubles!\n", 2);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fractol	fract;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fract.name = av[1];
		if (mandelbrot(fract))
			return (1);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "julia", 5))
	{
		ft_putstr_fd("You have to put 2 doubles after julia\n", 2);
		ft_putstr_fd("You can put julia 0.285 -0.01\n", 2);
		return (1);
	}
	else if ((ac > 1) && (ac < 5) && !ft_strncmp(av[1], "julia", 5))
	{
		fract.name = av[1];
		if (julia(av, fract))
			return (1);
	}
	else
		ft_putstr_fd("You have to put mandelbrot or julia", 2);
	return (0);
}
