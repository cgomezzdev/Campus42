/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:10:31 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/27 20:27:57 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTORL
# define FRACTORL

# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double x; // real
	double y; // imaginario

}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	move_x;
	double	move_y;
	double	julia_x;
	double	julia_y;
	double	scale;
	int		iter;
}			t_fractol;

int			ft_strncmp(char *s1, char *s2, int n);
void		fractol_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);
void		fractol_data(t_fractol *fractol);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			handle_key(int k_pressed, t_fractol *fractol);
int			handle_mouse(int b_pressed, int x, int y, t_fractol *fractol);
int			handle_close(t_fractol *fractol);
double		ft_atod(char *s);
void		ft_putstr_fd(char *s, int fd);

#endif
