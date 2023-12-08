/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:02:09 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/14 16:02:11 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printerr(char *error, int option)
{
	if (!error)
		return (-1);
	ft_printf("%s", error);
	if (option == 0)
		return (0);
	exit(0);
}
