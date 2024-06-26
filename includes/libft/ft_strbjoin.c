/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/14 15:57:36 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strwdup(s2, len));
	len = len + ft_strlen(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	len = 0;
	while (s1[i] != '\0')
		array[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		array[len++] = s2[i++];
	array[len] = '\0';
	return (array);
}
