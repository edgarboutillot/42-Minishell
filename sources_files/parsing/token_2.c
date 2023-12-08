/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:23:40 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/24 09:23:42 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*join_character_strings(char *first_str, int *i)
{
	int		j;
	int		space;
	char	*str;
	char	*new_str;

	j = *i;
	space = 0;
	while (_char(g_data->input[j], g_data->input[j - 1]) && g_data->input[j])
		j++;
	if (g_data->input[j] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (_char(g_data->input[*i], g_data->input[(*i) - 1])
		&& g_data->input[*i])
		str[j++] = g_data->input[((*i)++)];
	if (space)
		while (g_data->input[*i] == ' ')
			(*i)++;
	str[j] = '\0';
	new_str = ft_strjoin(first_str, str);
	free(str);
	return (new_str);
}

char	*join_quoted_strings(char *first_str, int *i)
{
	int		j;
	int		space;
	char	*str;
	char	type;
	char	*new_str;

	type = g_data->input[*i];
	(*i)++;
	j = *i;
	space = 0;
	while (g_data->input[j] != type && g_data->input[j - 1] != '\\')
		j++;
	if (g_data->input[j + 1] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	copy_quoted_string(str, i, type, space);
	new_str = ft_strjoin(first_str, str);
	if (_quote(g_data->input[(*i) - 1], g_data->input[(*i) - 2])
		&& g_data->input[(*i)])
		new_str = join_quoted_strings(new_str, i);
	else if (_char(g_data->input[(*i) - 1], g_data->input[(*i) - 2])
		&& g_data->input[(*i)])
		new_str = join_character_strings(new_str, i);
	free(str);
	return (new_str);
}

char	*join_strings(char *first_str, int *i)
{
	if (_quote(g_data->input[*i], g_data->input[*i - 1]))
		first_str = join_quoted_strings(first_str, i);
	else if (_char(g_data->input[*i], g_data->input[*i - 1]))
		first_str = join_character_strings(first_str, i);
	return (first_str);
}

void	copy_quoted_string(char *str, int *i, char type, int space)
{
	int	j;

	j = 0;
	while (g_data->input[*i])
	{
		if (g_data->input[*i] == type && g_data->input[*i - 1] != '\\')
			break ;
		str[j++] = g_data->input[((*i)++)];
	}
	if (space)
	{
		(*i)++;
		while (g_data->input[*i] == ' ')
			(*i)++;
	}
	else
		(*i)++;
	str[j] = '\0';
}

int	count_quoted_string(int j, char type)
{
	while (g_data->input[j])
	{
		if (g_data->input[j] == type && g_data->input[j - 1] != '\\')
			break ;
		j++;
	}
	return (j);
}
