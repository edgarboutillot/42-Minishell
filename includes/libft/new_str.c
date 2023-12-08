/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:02:04 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/24 16:02:07 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_str(char *str)
{
	char	*new_str;
	int		len;

	len = ft_strlen(str);
	new_str = ft_calloc(sizeof(char), (len + 1));
	if (!new_str)
		return (NULL);
	return (new_str);
}
