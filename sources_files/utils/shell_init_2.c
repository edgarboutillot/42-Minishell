/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:46:16 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/12/05 14:16:30 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	save_env_to_file(void)
{
	int		fd;
	int		i;
	char	*path;

	path = ft_strbjoin(g_data->ms_dir, "/.env");
	fd = open(path, O_RDWR | O_TRUNC, 0644);
	free(path);
	i = -1;
	while (g_data->ev[++i])
		write(fd, g_data->ev[i], ft_strlen(g_data->ev[i]));
	close(fd);
}

void	load_env_from_file(void)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(g_data->ev_dir, O_RDONLY, 0644);
	i = count_lines(fd);
	if (close(fd) == -1)
		perror("close");
	fd = open(g_data->ev_dir, O_RDONLY, 0644);
	g_data->ev = malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		g_data->ev[i] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	g_data->ev[i] = NULL;
	if (close(fd) == -1)
		perror("close");
}
