/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:47:55 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/27 12:47:57 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_escaped_characters(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\\'
			&& ((_spec(str[i + 1], '\0')) || (_quote(str[i + 1], '\0'))))
			i++;
		j++;
	}
	return (j);
}

char	*remove_escaped_characters(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = count_escaped_characters(str);
	tmp = malloc(sizeof(char) * (j + 1));
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\\'
			&& ((_spec(str[i + 1], '\0')) || (_quote(str[i + 1], '\0'))
				|| str[i + 1] == '\\'))
			i++;
		tmp[j++] = str[i];
	}
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

int	has_escaped_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\'
			&& ((_spec(str[i + 1], '\0')) || (_quote(str[i + 1], '\0'))
				|| str[i + 1] == '\\'))
			return (1);
		i++;
	}
	return (0);
}

void	format_quote_list(void)
{
	t_slist	*tmp;

	tmp = g_data->s_list;
	while (tmp)
	{
		if (has_escaped_characters(tmp->str))
			tmp->str = remove_escaped_characters(tmp->str);
		if (tmp->type == 0 || tmp->type == 2)
			tmp->str = check_and_replace_variables(tmp->str);
		tmp = tmp->next;
	}
}

void	parse_and_format_input(void)
{
	g_data->input = ft_strtrim(g_data->input, " ");
	g_data->input = prepend_space_to_input();
	process_first_list();
	format_quote_list();
	process_second_list();
	clear_qlist(&g_data->s_list);
}
