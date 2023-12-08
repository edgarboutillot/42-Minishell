/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:47:44 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/26 08:47:46 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	initialize_new_line(void)
{
	g_data->nl_error = 0;
	g_data->first_call = 0;
	g_data->s_list = NULL;
	g_data->shell_list = NULL;
	if (g_data->exit_status == 258)
		g_data->exit_status = 0;
}

void	process_quotes(int *i, int *quote, char *type)
{
	while (g_data->input[++(*i)])
	{
		if (_quote(g_data->input[*i], g_data->input[(*i) - 1]) && !(*type))
		{
			*type = g_data->input[*i];
			(*quote)++;
			(*i)++;
		}
		if (g_data->input[*i] == *type)
		{
			*quote = 0;
			*type = 0;
		}
	}
}

int	validate_quotes(void)
{
	int		i;
	int		quote;
	char	type;

	i = -1;
	quote = 0;
	type = 0;
	if (_quote(g_data->input[0], '\0'))
	{
		type = g_data->input[0];
		quote++;
	}
	i++;
	process_quotes(&i, &quote, &type);
	if (quote % 2 != 0)
	{
		g_data->nl_error = 1;
		return (printf("minishell: syntax error: quote error\n"));
	}
	return (0);
}

int	check_new_line_error(void)
{
	int	i;

	i = -1;
	if (g_data->input == NULL)
		return (g_data->nl_error = 1, 1);
	if (g_data->input[0] == '\0')
		return (g_data->nl_error = 1, 1);
	if (validate_quotes())
		return (g_data->nl_error = 2, 1);
	while (g_data->input[++i])
	{
		if (_char(g_data->input[i], '\0'))
			return (0);
		if (_space(g_data->input[i]))
		{
			while (_space(g_data->input[i]) && g_data->input[i])
				i++;
			if (g_data->input[i] == '\0')
				return (g_data->nl_error = 1, 1);
		}
	}
	return (0);
}

void	process_new_line(void)
{
	if (g_data->first_call == 0)
		clear_shell_list(&g_data->shell_list);
	initialize_new_line();
	if (check_new_line_error())
		return ;
}
