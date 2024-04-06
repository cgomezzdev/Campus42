/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:36 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/04/06 19:28:23 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

char *ft_strjoin(char const *s1,char const *s2)
{

}
