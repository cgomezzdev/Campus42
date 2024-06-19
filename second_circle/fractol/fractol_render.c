/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:53:17 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/19 19:43:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Funcion para escalar la imagen del ancho de la pantalla a lo que necestiamos mostar.
double	map_scale(double scaled_num, double new_min, double, new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (scaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

static void	handle_piexl(int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			iter;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map_scale(y, +2, -2, 0 799);
	c.y = map_scale(y, +2, -2, 0 799);
	// Bucle para cuantas veces queremos iterar cuanto mas iteramos mas definicion
	// pero tambien le costara mas trabajo renderizar.
	i = 0;
	iter = 42;
	while (i < iter)
	{
		z = sum_comples(square_complex(z), c);
		// Si la hipotenusa es mayour que 2 asumimis que el punto esta fuera.
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_v)
		{
			my_mlx_pixel_put(&fractol->img, x, y, color);
			color = map(i, 0X000000, 0xFFFFFF, iter);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractol->im, x, y, 0x0000FF);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
		{
			handle_piexl(x, y);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, mlx_ptr,
		fractol->mlx_window, win_ptr, fractol->img.img_ptr, img_ptr 0, 0);
}
