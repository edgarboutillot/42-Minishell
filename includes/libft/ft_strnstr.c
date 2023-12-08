/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:00:00 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/14 16:00:03 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	if ((!len || !big) && !len)
		return (NULL);
	while (*big && len >= ft_strlen(little))
	{
		i = 0;
		while (big[i] == little[i] && i < len)
		{
			if (!little[i + 1])
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
