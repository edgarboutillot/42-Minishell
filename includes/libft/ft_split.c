/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:42:07 by edboutil          #+#    #+#             */
/*   Updated: 2023/11/14 15:57:28 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_char(char c, char charset)
{
	if (c == charset || c == '\0')
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (verif_char(s[i + 1], c) && !verif_char(s[i], c))
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, char const *s, char c)
{
	int	i;

	i = 0;
	while (!verif_char(s[i], c))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

static void	write_string(char **array, char const *s, char c)
{
	int	i;
	int	j;
	int	string;

	string = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (verif_char(s[i], c))
			i++;
		else
		{
			j = 0;
			while (!verif_char(s[i + j], c))
				j++;
			array[string] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(array[string], s + i, c);
			i += j;
			string++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = 0;
	write_string(array, s, c);
	return (array);
}
