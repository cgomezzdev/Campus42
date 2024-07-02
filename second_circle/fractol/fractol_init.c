/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:01:14 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/02 21:42:52 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	malloc_error(void)
{
	ft_putstr_fd("Problem with malloc\n", 2);
	return (1);
}

void	fractol_data(t_fractol *fractol)
{
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->scale = 1.0;
	fractol->iter = 42;
}

static void	fractol_events(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->mlx_window, handle_mouse, fractol);
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, handle_key, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, EnterWindowMask, handle_close,
		fractol);
}

int	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		return (malloc_error());
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, 800, 800,
			fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		return (malloc_error());
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, 800, 800);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		return (malloc_error());
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	fractol_data(fractol);
	fractol_events(fractol);
	return (0);
}
