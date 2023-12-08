/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:24:10 by edboutil          #+#    #+#             */
/*   Updated: 2023/12/05 14:24:39 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_prompt(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!g_data->exit_status)
		ft_putstr_fd("\033[1;32m\033[1", 2);
	else
		ft_putstr_fd("\033[1;31m\033[1", 2);
	ft_putchar_fd(g_data->ev_user[0], 2);
	ft_putstr_fd(g_data->ev_user, 2);
	ft_putstr_fd("\033[0;37m", 2);
	ft_putstr_fd(" in ", 2);
	ft_putstr_fd("\e[1;93m", 2);
	ft_putstr_fd(pwd, 2);
	ft_putstr_fd("\033[0m", 2);
	ft_putstr_fd("\n", 2);
	free(pwd);
}

void	free_minishell(void)
{
	clear_shell_list(&g_data->shell_list);
	free(g_data->line);
	free(g_data->ev_dir);
	free(g_data->ms_dir);
	free(g_data->ev_user);
	close(g_data->old_fd[0]);
	close(g_data->old_fd[1]);
	remove_file(get_base_path(g_data->ev), "/.env", g_data->ev);
	if (g_data->ev_status)
		free_char(g_data->ev_path, get_char_size(g_data->ev_path));
	free_char(g_data->ev, get_char_size(g_data->ev));
	free(g_data);
}

void	reset_fd(void)
{
	dup2(g_data->old_fd[0], 0);
	dup2(g_data->old_fd[1], 1);
}
