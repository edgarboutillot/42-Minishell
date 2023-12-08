/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzentout <bzentout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:28 by bzentout          #+#    #+#             */
/*   Updated: 2023/12/05 15:02:47 by bzentout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"

int	flag_nl(char *flag)
{
	int	i;

	i = 0;
	if (ft_strlen(flag) <= 1)
		return (0);
	if (flag[0] != '-')
		return (0);
	while (flag[++i])
		if (flag[i] != 'n')
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	flag;

	(void)ac;
	flag = flag_nl(av[1]);
	while (av[++flag])
	{
		printf("%s", av[flag]);
		if (av[flag + 1])
			printf(" ");
	}
	if (!flag_nl(av[1]))
		printf("\n");
	return (0);
}
