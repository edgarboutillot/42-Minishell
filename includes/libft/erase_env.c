/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:50:24 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/14 15:50:27 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	erase_env(char **ev)
{
	char	*path;
	char	**args;
	pid_t	pid;

	path = get_base_path(ev);
	path = ft_strjoin(path, "/.env2");
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("rm");
	args[1] = ft_strdup(path);
	args[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/rm", args, ev);
	else
		waitpid(pid, NULL, 0);
	free(path);
	free_char(args, 3);
}
