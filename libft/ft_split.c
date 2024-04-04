/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:07:23 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/02/07 20:52:04 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++count;
		i++;
	}
	return (count);
}

static char	*ft_create_words(char const *s, char c, int *pos)
{
	char	*word;
	int		in;
	int		end;

	in = 0;
	end = 0;
	while (s[in] == c && s[in])
		in++;
	end = in;
	while (s[end] != c && s[end])
	{
		end++;
	}
	word = ft_substr(s, in, end - in);
	if (word == NULL)
		return (NULL);
	*pos += end;
	return (word);
}

static void	ft_free(char **split, int words)
{
	int	i;

	i = 0;
	while (i != words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	words = ft_count_words(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < words)
	{
		split[i] = ft_create_words(s + pos, c, &pos);
		if (split[i] == NULL)
		{
			ft_free(split, i);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
