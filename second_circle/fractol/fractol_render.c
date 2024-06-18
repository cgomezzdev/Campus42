/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:53:17 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/18 22:20:56 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define REAL 0
#define IMAG 1

#include "fractol.h"

// Funcion para escalar la imagen del ancho de la pantalla a lo que necestiamos mostar.
double	map_scale(double scaled_num, double new_min, double, new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (scaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

void	handle_piexl(int x, int y)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map_scale(y, +2, -2, 0 799);
	c.y = map_scale(y, +2, -2, 0 799);
	// Bucle para cuantas veces queremos iterar
	while ()
	{
		z = sum_comples(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_v)
		{
			my_mlx_pixel_put();
			return ;
		}
	}
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
}
