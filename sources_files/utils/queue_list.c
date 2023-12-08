/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:02:15 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/11 15:02:15 by edgarboutil     ###   ########lyon.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_slist	*create_qlist_node(char *str, int type)
{
	t_slist	*new;

	new = malloc(sizeof(t_slist));
	new->str = ft_strdup(str);
	new->type = type;
	new->next = NULL;
	return (new);
}

t_slist	*get_last_qlist_node(t_slist *lst)
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

void	add_node_to_qlist_back(t_slist **lst, t_slist *new)
{
	t_slist	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = get_last_qlist_node(*lst);
	last->next = new;
}

void	clear_qlist(t_slist **lst)
{
	t_slist	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
}
