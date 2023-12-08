/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:44:59 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/16 13:29:52 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*prepend_space_to_input(void)
{
	char	*tmp;
	char	*tmp2;

	tmp = g_data->input;
	tmp2 = ft_strbjoin(" ", tmp);
	free(tmp);
	return (tmp2);
}

void	display_command_list(void)
{
	t_shell	*tmp;
	int		i;

	tmp = g_data->shell_list;
	i = -1;
	while (tmp)
	{
		i = -1;
		printf("--------------------\033[0m\n");
		while (tmp->words[++i])
			printf("\t%s\n", tmp->words[i]);
		printf("--                --\n");
		printf("  \033[0;90mtype: \033[1m%d\033[0m\n", tmp->type);
		printf("  \033[0;33msize: \033[1m%d\033[0m\n", tmp->size);
		printf("--------------------\033[0m\n");
		if (tmp->next != NULL)
			printf("\033[0;47mMaillon suivant ->  \033[0m\n");
		else
			printf("Dernier maillon\n");
		tmp = tmp->next;
	}
}

t_shell	*get_command_location(int i)
{
	t_shell	*tmp;
	int		j;

	tmp = g_data->shell_list;
	j = 0;
	while (tmp)
	{
		if (j == i)
			return (tmp);
		if (tmp->type == 1)
			j++;
		tmp = tmp->next;
	}
	return (NULL);
}

void	update_ret_env_variable(char *str)
{
	int	i;

	i = -1;
	while (g_data->ev[++i])
	{
		if (ft_strncmp(g_data->ev[i], "R=", 2) == 0)
		{
			free(g_data->ev[i]);
			g_data->ev[i] = ft_strdup(str);
			free(str);
			return ;
		}
	}
	free(str);
}

void	handle_exit_status(int option)
{
	char	*str;
	char	*nb;

	if (!option)
	{
		if (WIFEXITED(g_data->ret))
			g_data->exit_status = WEXITSTATUS(g_data->ret);
		if (WIFSIGNALED(g_data->ret))
			g_data->exit_status = WTERMSIG(g_data->ret);
		if (WCOREDUMP(g_data->ret))
			g_data->exit_status = WCOREDUMP(g_data->ret);
		if (g_data->ret == 256)
			g_data->exit_status = 1;
	}
	str = malloc(sizeof(char) * 3);
	str[0] = 'R';
	str[1] = '=';
	str[2] = '\0';
	nb = ft_itoa(g_data->exit_status);
	str = ft_strjoin(str, nb);
	str = ft_strjoin(str, "\n");
	update_ret_env_variable(str);
	free(nb);
	save_env_to_file();
}
