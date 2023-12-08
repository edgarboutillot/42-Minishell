/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzentout <bzentout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:20 by bzentout          #+#    #+#             */
/*   Updated: 2023/12/05 14:43:21 by bzentout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	new_command_init(void)
{
	g_data->redirect = 0;
	g_data->nb_redirect = 0;
	g_data->builtin = 0;
	g_data->cmd_error = 0;
	g_data->redir_in = NULL;
	g_data->redir_out = NULL;
	g_data->updater = 0;
}

int	get_words_size(t_shell *tmp)
{
	int		i;

	i = tmp->size;
	if (!g_data->redirect)
		return (i);
	while (tmp && tmp->type != 1)
	{
		if (tmp->type == 2 || tmp->type == 3
			|| tmp->type == 4 || tmp->type == 5)
			i += tmp->next->size - 1;
		tmp = tmp->next;
	}
	return (i);
}

char	**add_after_redirections(t_shell *tmp, char **words)
{
	int		i;
	int		j;

	j = -1;
	while (tmp && tmp->type != 1)
	{
		if (tmp->type == 0)
		{
			i = -1;
			while (++i < tmp->size)
				words[++j] = ft_strdup(tmp->words[i]);
		}
		if (tmp->type == 2 || tmp->type == 3
			|| tmp->type == 4 || tmp->type == 5)
		{
			copy_redirections(tmp);
			tmp = tmp->next;
			i = 0;
			if (tmp->words[1])
				while (++i < tmp->size)
					words[++j] = ft_strdup(tmp->words[i]);
		}
		tmp = tmp->next;
	}
	return (words);
}

char	**get_command_words(int i)
{
	t_shell	*tmp;
	char	**words;
	int		words_size;

	tmp = get_command_location(i);
	words_size = get_words_size(tmp);
	if (g_data->redirect == 0)
		return (double_chardup(tmp->words, tmp->size));
	words = malloc(sizeof(char *) * (words_size + 1));
	words = add_after_redirections(tmp, words);
	words[words_size] = NULL;
	return (words);
}

void	check_redirections(int i)
{
	t_shell	*tmp;

	tmp = get_command_location(i);
	while (tmp && tmp->type != 1)
	{
		if (tmp->type == 2)
			g_data->redirect |= 1 << 0;
		else if (tmp->type == 3)
			g_data->redirect |= 1 << 1;
		else if (tmp->type == 4)
			g_data->redirect |= 1 << 2;
		else if (tmp->type == 5)
			g_data->redirect |= 1 << 3;
		tmp = tmp->next;
	}
	i = 0;
	while (i < 4)
	{
		if ((g_data->redirect & (1 << i)) != 0)
			g_data->nb_redirect++;
		i++;
	}
}
