/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:53:31 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/14 15:53:34 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_char(char c, char d)
{
	if (c > ' ' && c < 127 && !_spec(c, d) && !_quote(c, d))
		return (1);
	return (0);
}
