/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:51:59 by edboutil          #+#    #+#             */
/*   Updated: 2023/11/14 15:58:16 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *src)
{
	int		len;
	char	*str;
	int		i;

	i = -1;
	len = ft_strlen(src);
	str = (char *)malloc(len * sizeof(char) + 1);
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
