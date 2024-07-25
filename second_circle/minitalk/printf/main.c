/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:43:22 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/03/24 21:20:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("Num char imprimidos: %i\n", ft_printf("%c %d %p\n", 'a', 3, ""));
	printf("Num char imprimidos: %i\n", printf("%c % d %p\n", 'a', 3, ""));
}
