/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:33:50 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/19 15:39:19 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char reverse_bits(unsigned char octet)
{
	return (((octet >> 0) & 1) << 7) |\
               (((octet >> 1) & 1) << 6) |\
               (((octet >> 2) & 1) << 5) |\
               (((octet >> 3) & 1) << 4) |\
               (((octet >> 4) & 1) << 3) |\
               (((octet >> 5) & 1) << 2) |\
               (((octet >> 6) & 1) << 1) |\
               (((octet >> 7) & 1) << 0);
}
