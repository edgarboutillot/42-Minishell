/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:45:05 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/16 13:29:55 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_file(char *path, char *file, char **ev)
{
	char	**args;
	pid_t	pid;

	path = ft_strjoin(path, file);
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("rm");
	args[1] = ft_strdup(path);
	args[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/rm", args, ev);
	else
		waitpid(pid, NULL, 0);
	free_char(args, 3);
	free(path);
}

int	get_shell_level(void)
{
	int	i;
	int	lvl;

	i = -1;
	while (g_data->ev[++i])
		if (!ft_strncmp("SHLVL=", g_data->ev[i], 6))
			break ;
	lvl = ft_atoi(g_data->ev[i] + 6);
	return (lvl);
}

void	decrease_shell_level(void)
{
	int		i;
	int		lvl;
	char	*tmp;

	i = -1;
	while (g_data->ev[++i])
		if (!ft_strncmp("SHLVL=", g_data->ev[i], 6))
			break ;
	lvl = ft_atoi(g_data->ev[i] + 6) - 1;
	tmp = ft_itoa(lvl);
	free(g_data->ev[i]);
	g_data->ev[i] = ft_strbjoin("SHLVL=", tmp);
	g_data->ev[i] = ft_strjoin(g_data->ev[i], "\n");
	free(tmp);
}
