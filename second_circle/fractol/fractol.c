/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:47:15 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/27 22:20:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	check_double(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			i++;
		if (!ft_isdigit(s[i]))
			return (1);
		if (s[i])
			i++;
	}
	if (s[i])
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	off_set;

	off_set = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + off_set) = color;
}

void	mandelbrot(t_fractol fract)
{
	fractol_init(&fract);
	fractol_render(&fract);
	mlx_loop(fract.mlx_connection);
}

void	julia(int ac, char *av[], t_fractol fract)
{
	if (ac == 4)
	{
		ft_putstr_fd("All good!\n", 1);
		// Julia paramaetros entre 2 y -2.
		if (!ft_strncmp(fract.name, "julia", 5))
		{
			if (!check_double(av[2]) && !check_double(av[3]))
			{
				fract.julia_x = ft_atod(av[2]);
				fract.julia_y = ft_atod(av[3]);
				fractol_init(&fract);
				fractol_render(&fract);
				mlx_loop(fract.mlx_connection);
			}
			else
				ft_putstr_fd("No doubles.\n", 2);
		}
		else
		{
			ft_putstr_fd("julia needs 2 doubles!\n", 2);
			ft_putstr_fd("You can put julia 0.285 -0.01", 2);
		}
	}
}

int	main(int ac, char *av[])
{
	t_fractol	fract;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fract.name = av[1];
		mandelbrot(fract);
	}
	else if ((ac > 1) && (ac < 5) && !ft_strncmp(av[1], "julia", 5))
	{
		fract.name = av[1];
		julia(ac, av, fract);
	}
	else
	{
		ft_putstr_fd("You have to put mandelbrot or julia!", 2);
	}
	return (0);
}
