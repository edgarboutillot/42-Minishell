/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzentout <bzentout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:34 by bzentout          #+#    #+#             */
/*   Updated: 2023/12/05 15:09:45 by bzentout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"

int	main(int ac, char **av, char **ev)
{
	int	i;

	(void)ac;
	(void)av;
	i = 1;
	if (!ev)
		printf("\n");
	while (ev[++i])
		printf("%s", ev[i]);
	return (0);
}
