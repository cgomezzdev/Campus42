/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:10:31 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/18 22:21:35 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTORL
#define FRACTORL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <mlx.h>

typedef struct s_complex{
	double x; //real
	double y; //imaginario
	
} t_complex;

typedef struct s_img{
	void *img_ptr;
	char *pixels_ptr;
	int bpp;
	int endian;
	int line_len;
} t_img;

typedef struct s_fractol{
	char *name;
	void *mlx_connection;
	void *mlx_window;
	t_img img;
	double escape_v;
} t_fractol;

int	ft_strncmp(char *s1, char *s2, int n);
void fractol_init(t_fractol *fractol);
t_complex sum_complex(t_complex z1,t_complex z2);
t_complex square_complex(t_complex z);








#endif
