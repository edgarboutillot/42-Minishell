/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:46:20 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/12/05 14:24:33 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	display_prompt(void);
void	free_minishell(void);
void	reset_fd(void);

t_data	*g_data;

int	main(int ac, char **av, char **ev)
{
	g_data = malloc(sizeof(t_data));
	setup_minishell_environment(ac, av, ev);
	while (g_data->status)
	{
		reset_fd();
		display_prompt();
		g_data->input = readline("$> ");
		if (g_data->input == NULL)
			handle_ctrl_d();
		process_new_line();
		if (g_data->nl_error == 0 || g_data->nl_error == 2)
		{
			add_history(g_data->input);
			if (g_data->nl_error == 0)
			{
				parse_and_format_input();
				process_interpreted_strings();
				if (g_data->exit_status != 258)
					execute_commands();
			}
		}
		free(g_data->input);
	}
	free_minishell();
	return (0);
}
