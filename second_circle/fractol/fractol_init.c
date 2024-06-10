/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:01:14 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/10 20:55:27 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol)
}
