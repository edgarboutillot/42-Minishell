/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:42:41 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/16 23:23:03 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_shell	*create_s_node(char **content, int type, int size)
{
	t_shell	*list;

	list = (t_shell *)malloc(sizeof(t_shell));
	list->words = double_chardup(content, size);
	list->type = type;
	if (type == 1)
	{
		if (content[0][0] == '|')
			list->type = 1;
		else if (content[0][0] == '<' && content[0][1] != '<')
			list->type = 2;
		else if (content[0][0] == '>' && content[0][1] != '>')
			list->type = 3;
		else if (content[0][0] == '>' && content[0][1] == '>')
			list->type = 4;
		else if (content[0][0] == '<' && content[0][1] == '<')
			list->type = 5;
		else if (content[0][0] == ';')
			list->type = 6;
		else if (content[0][0] == '&')
			list->type = 7;
	}
	list->size = size;
	list->next = NULL;
	return (list);
}

t_shell	*get_last_shell_node(t_shell *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	add_node_to_back(t_shell **lst, t_shell *new)
{
	t_shell	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = get_last_shell_node(*lst);
	last->next = new;
}

void	clear_shell_list(t_shell **lst)
{
	t_shell	*tmp;
	int		i;

	i = -1;
	if (!lst)
		return ;
	while (*lst)
	{
		i = -1;
		tmp = *lst;
		while (++i < (*lst)->size)
			free((*lst)->words[i]);
		free((*lst)->words);
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}
