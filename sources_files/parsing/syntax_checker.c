/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:49:23 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/24 13:18:32 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	validate_syntax(void)
{
	t_shell	*tmp;

	tmp = g_data->shell_list;
	while (tmp)
	{
		if (tmp->type != 0 && tmp->next && tmp->next->type != 0)
		{
			printf("minishell: syntax error near unexpected token `");
			g_data->exit_status = 258;
			return (printf("%s'\n", tmp->next->words[0]), 1);
		}
		if (tmp->type != 0 && tmp->next == NULL)
		{
			printf("minishell: syntax error near unexpected token `");
			g_data->exit_status = 258;
			return (printf("%s'\n", tmp->words[0]), 1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	calculate_command_count(void)
{
	t_shell	*tmp;
	int		len;

	tmp = g_data->shell_list;
	len = 0;
	while (tmp)
	{
		if (tmp->type == 1)
			len++;
		tmp = tmp->next;
	}
	g_data->command = len + 1;
}

void	process_interpreted_strings(void)
{
	if (validate_syntax())
	{
		handle_exit_status(1);
		return ;
	}
	calculate_command_count();
}
