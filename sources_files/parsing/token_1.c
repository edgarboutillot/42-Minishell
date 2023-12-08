/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:15:28 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/24 19:15:28 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_and_add_quote(int *i)
{
	int		j;
	int		space;
	char	*str;
	char	type;

	type = g_data->input[*i];
	(*i)++;
	j = *i;
	space = 0;
	j = count_quoted_string(j, type);
	if (g_data->input[j + 1] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	copy_quoted_string(str, i, type, space);
	if (!_space(g_data->input[(*i) - 1]) && g_data->input[(*i)])
		str = join_strings(str, i);
	if (type == '\'')
		add_node_to_qlist_back(&g_data->s_list, create_qlist_node(str, 1));
	else if (type == '\"')
		add_node_to_qlist_back(&g_data->s_list, create_qlist_node(str, 2));
	free(str);
}

void	parse_and_add_special_character(int *i)
{
	int		j;
	int		space;
	char	*str;

	j = *i;
	space = 0;
	while (_spec(g_data->input[j], g_data->input[j - 1]))
		j++;
	if (g_data->input[j] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (_spec(g_data->input[*i], g_data->input[(*i) - 1]))
		str[j++] = g_data->input[((*i)++)];
	if (space)
		while (g_data->input[*i] == ' ')
			(*i)++;
	str[j] = '\0';
	add_node_to_qlist_back(&g_data->s_list, create_qlist_node(str, 3));
	free(str);
}

void	parse_and_add_character(int *i)
{
	int		j;
	int		space;
	char	*str;

	j = (*i);
	space = 0;
	while (_char(g_data->input[j], g_data->input[j - 1]))
		j++;
	if (g_data->input[j] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (_char(g_data->input[*i], g_data->input[(*i) - 1]))
		str[j++] = g_data->input[((*i)++)];
	if (space)
		while (g_data->input[*i] == ' ')
			(*i)++;
	str[j] = '\0';
	add_node_to_qlist_back(&g_data->s_list, create_qlist_node(str, 0));
	free(str);
}

void	process_first_list(void)
{
	int		i;

	i = 1;
	while (g_data->input[i])
	{
		if (_char(g_data->input[i], g_data->input[i - 1]))
			parse_and_add_character(&i);
		else if (_spec(g_data->input[i], g_data->input[i - 1]))
			parse_and_add_special_character(&i);
		else if (_quote(g_data->input[i], g_data->input[i - 1]))
			parse_and_add_quote(&i);
		if (g_data->input[i] == '\0')
			break ;
	}
}
