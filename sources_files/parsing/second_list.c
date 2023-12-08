/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:12:22 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/28 10:12:24 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_list_item(char ***words, int *allocated, int *i, t_slist *tmp)
{
	if (*allocated == 0)
	{
		*words = (char **)malloc(sizeof(char *));
		(*words)[0] = ft_strdup(tmp->str);
		*i = 1;
		*allocated = 1;
	}
	else
	{
		*words = str_to_tab(*words, tmp->str, (*i)++, 0);
	}
	if (tmp->next == NULL || tmp->next->type == 3)
	{
		*words = str_to_tab(*words, NULL, *i, 0);
		add_node_to_back(&g_data->shell_list, create_s_node(*words, 0, *i));
		free_char(*words, *i);
		*words = NULL;
		*allocated = 0;
	}
}

void	process_second_list(void)
{
	char	**words;
	int		allocated;
	int		i;
	t_slist	*tmp;

	allocated = 0;
	words = NULL;
	tmp = g_data->s_list;
	while (tmp)
	{
		if (tmp->type != 3)
			process_list_item(&words, &allocated, &i, tmp);
		else
		{
			words = (char **)malloc(sizeof(char *) * 2);
			words[0] = ft_strdup(tmp->str);
			words[1] = NULL;
			add_node_to_back(&g_data->shell_list, create_s_node(words, 1, 1));
			free_char(words, 2);
			words = NULL;
		}
		tmp = tmp->next;
	}
}
