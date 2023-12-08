/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzentout <bzentout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:53 by bzentout          #+#    #+#             */
/*   Updated: 2023/12/05 15:10:35 by bzentout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft/libft.h"

int	main(int ac, char **av)
{
	char	pwd[1024];

	(void)ac;
	(void)av;
	getcwd(pwd, sizeof(pwd));
	printf("%s\n", pwd);
}
