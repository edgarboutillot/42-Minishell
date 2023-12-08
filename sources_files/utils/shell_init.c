/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:46:16 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/12/05 14:16:30 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	setup_default_environment(char **ev)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(".env", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (ev[++i])
	{
		write(fd, ev[i], ft_strlen(ev[i]));
		write(fd, "\n", 1);
	}
	if (g_data->ev_status == 0)
	{
		write(fd, "USER=", 5);
		write(fd, g_data->ev_user, ft_strlen(g_data->ev_user));
		write(fd, "\n", 1);
		write(fd, "SHLVL=1\n", 8);
		write(fd, "HOME=/nfs/home/", 15);
		write(fd, g_data->ev_user, ft_strlen(g_data->ev_user));
		write(fd, "\n", 1);
	}
	write(fd, "BASEDIR=", 8);
	write(fd, g_data->ms_dir, ft_strlen(g_data->ms_dir));
	write(fd, "\n", 1);
	write(fd, "R=0\n", 4);
	close(fd);
}

void	verify_and_set_user_env(char **ev)
{
	int	i;

	i = 0;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
			g_data->ev_path = ft_split(ev[i] + 5, ':');
		if (ft_strncmp(ev[i], "USER=", 5) == 0)
			g_data->ev_user = ft_strdup(ev[i] + 5);
		i++;
	}
	if (i != 0)
		g_data->ev_status = 1;
	else
	{
		g_data->ev_status = 0;
		g_data->ev_path = NULL;
		g_data->ev_user = readline("Please enter an username: ");
	}
}

void	init_fd_status(void)
{
	g_data->status = 1;
	g_data->exit_status = 0;
	g_data->old_fd[0] = dup(0);
	g_data->old_fd[1] = dup(1);
	g_data->first_call = 1;
	g_data->cmd_error = 0;
}

void	setup_minishell_environment(int ac, char **av, char **ev)
{
	(void)ac;
	(void)av;
	verify_and_set_user_env(ev);
	init_fd_status();
	g_data->ms_dir = getcwd(NULL, 0);
	g_data->ev_dir = ft_strjoin(getcwd(NULL, 0), "/.env");
	setup_default_environment(ev);
	load_env_from_file();
	g_data->line = ft_strbjoin(g_data->ev_user, "@minishell$> ");
	toggle_control(0);
	signal(SIGQUIT, handle_signal_quit);
	initialize_signal_handling();
}
