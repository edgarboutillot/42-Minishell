/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:26:54 by edboutil          #+#    #+#             */
/*   Updated: 2023/11/14 15:58:24 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*array;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	array = (char *)malloc(size * sizeof(char));
	if (!array)
		return (NULL);
	ft_memcpy(array, s, size);
	return (array);
}
