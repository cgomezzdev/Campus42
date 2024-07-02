/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:53:17 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/28 19:02:38 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_scale(double scaled_num, double new_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (scaled_num - 0) / (old_max - 0) + new_min);
}

static void	mandel_or_juli(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_piexl(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (map_scale(x, -2, +2, 799) * fractol->scale) + fractol->move_x;
	z.y = (map_scale(y, +2, -2, 799) * fractol->scale) + fractol->move_y;
	mandel_or_juli(&z, &c, fractol);
	i = 0;
	while (i < fractol->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map_scale(i, 0X0000FF, 0XFFFFFF, fractol->iter);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractol->img, x, y, 0X000000);
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
			handle_piexl(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
