/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:54:59 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/24 17:52:30 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && n > 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}
/*Funcion para calucular numero real e imaginario
  real = (x^2 - y^2)
  imaginario = 2*x*y*/
t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

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
	//printf("Key pressed:%d\n", k_pressed);
	// Chekear esta parte porque deferia funcionar la la variable de la liberia.
	if (k_pressed == 65307)
		handle_close(fractol);
	else if (k_pressed == 65363)
		fractol->move_x += 0.5;
	else if (k_pressed == 65361)
		fractol->move_x -= 0.5;
	else if (k_pressed == 65362)
		fractol->move_y += 0.5;
	else if (k_pressed == 65364)
		fractol->move_y -= 0.5;
	fractol_render(fractol);
	return (0);
}
int	handle_mouse(int b_pressed,int x, int y, t_fractol *fractol)
{
	printf("x%d and y%d\n",x,y);
	printf("mouse pressed:%d\n", b_pressed);
	if (b_pressed == 4)
		fractol->scale *= 0.92;
	else if (b_pressed == 5)
		fractol->scale *= 1.04;
	else if (b_pressed == 1)
		fractol->iter += 10;
	else if (b_pressed == 3)
		fractol->iter -= 10;
	fractol_render(fractol); // Para actualizar los datos.
	return (0);
}
