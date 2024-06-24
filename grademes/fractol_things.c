/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:07:36 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/15 19:07:48 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(void /*int ac, char *av[]*/)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		x;
	int		y;

	x = 5;
	y = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "Hello world!");
	img.img_ptr = mlx_new_image(mlx, 960, 540);
	/*if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		printf("All good!\n");
	}
	else
	{
		printf("Error\n");
	}*/
	img.pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len,
			&img.endian);
	while (x < 200 && y < 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		x++;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}
