/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:21:22 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/05/07 22:54:56 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	max(int *tab, unsigned int len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < len)
	{
		if (tmp < tab[i])
			tmp = tab[i];
		i++;
	}
	return (tmp);
}
/*
int	main(void)
{
	int	tab[4] = {};

	max(tab, 4);
	return (0);
}*/
