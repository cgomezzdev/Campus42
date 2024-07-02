/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:18:59 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/29 19:08:04 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	handle_key(int k_pressed, t_fractol *fractol)
{
	if (k_pressed == 65307)
		handle_close(fractol);
	else if (k_pressed == 65363)
		fractol->move_x += 0.05;
	else if (k_pressed == 65361)
		fractol->move_x -= 0.05;
	else if (k_pressed == 65362)
		fractol->move_y += 0.05;
	else if (k_pressed == 65364)
		fractol->move_y -= 0.05;
	else if (k_pressed == 32)
		fractol_data(fractol);
	fractol_render(fractol);
	return (0);
}

int	handle_mouse(int b_pressed, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (b_pressed == 4)
		fractol->scale *= 0.92;
	else if (b_pressed == 5)
		fractol->scale *= 1.04;
	else if (b_pressed == 1)
		fractol->iter += 10;
	else if (b_pressed == 3)
		fractol->iter -= 10;
	fractol_render(fractol);
	return (0);
}
