/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:41:50 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/06/07 18:45:07 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

int	main(void)
{
	t_complex	z;
	t_complex	c;
	double		tmp_r;

	z.r = 0;
	z.i = 0;
	c.r = 0.25;
	c.i = 0.4;
	for (int i = 0; i < 42; i++)
	{
		// General formula
		// z = x^2 + c
		tmp_r = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i;
		z.r = tmp_r;
		// Adding the c value
		z.r += c.r;
		z.i += c.i;
		printf("iteratcion -> %d real %f imaginary%f\n", i, z.r, z.i);
	}
}
