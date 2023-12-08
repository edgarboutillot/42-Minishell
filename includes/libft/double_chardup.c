/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_chardup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:50:20 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/14 15:50:22 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**double_chardup(char **str, int size)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (size + 1));
	while (i <= size)
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	return (new);
}
