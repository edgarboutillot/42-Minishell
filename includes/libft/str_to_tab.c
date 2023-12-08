/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:02:16 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/26 16:02:23 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_tab(char **tab, int size, int option)
{
	int		i;
	char	**new_tab;

	i = -1;
	new_tab = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		if (option == 0 || option == 2)
			new_tab[i] = ft_strdup(tab[i]);
		else
			new_tab[i] = tab[i];
	}
	return (new_tab);
}

char	**str_to_tab(char **tab, char *str, int size, int option)
{
	int		i;
	char	**new_tab;

	i = -1;
	new_tab = copy_tab(tab, size, option);
	while (++i < size)
		;
	if (str != NULL)
	{
		if (option == 0)
			new_tab[i] = ft_strdup(str);
		else
			new_tab[i] = str;
	}
	else
		new_tab[size] = NULL;
	i = -1;
	if (option == 0 || option == 2)
	{
		while (++i < size)
			free(tab[i]);
		free(tab);
	}
	return (new_tab);
}
