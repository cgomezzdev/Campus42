/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:47:53 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/07/07 22:29:30 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for(int i=1; i < ac; i++)
	{
		std::string arg = av[i];
		for(size_t j = 0; j < arg.length(); j++)
			std::cout << static_cast<char>(std::toupper(arg[j]));
	}
	std::cout << std::endl;
	return (0);
}
