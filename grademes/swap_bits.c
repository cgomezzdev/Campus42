/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:32:40 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/19 15:33:38 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octect << 4));
}
