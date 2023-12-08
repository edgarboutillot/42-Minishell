/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:00:49 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/20 16:00:59 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_base_path(char **ev)
{
	int	i;
	int	found;
	int	len;

	i = -1;
	found = 0;
	while (ev[++i])
	{
		if (ft_strncmp(ev[i], "BASEDIR=", 8) == 0)
		{
			found = 1;
			break ;
		}
	}
	if (found == 0)
		return (NULL);
	len = ft_strlen(ev[i] + 8);
	return (ft_strwdup(ev[i] + 8, len - 1));
}
