/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:49:28 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/10/23 13:22:57 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_variable_name(char *str)
{
	char	*new_str;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	while (str[++i] && _char(str[i], str[i - 1]))
		j++;
	new_str = malloc(sizeof(char) * (j + 2));
	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	while (_char(str[i], '\0'))
		new_str[j++] = str[++i];
	new_str[j] = '\0';
	if (new_str[j - 1] == ' ' || new_str[j - 1] == '\'')
		new_str[j - 1] = '\0';
	new_str = check_special_characters(new_str);
	tmp = get_environment_variable(new_str);
	return (tmp);
}

char	*quote_variable(char *str, char *tmp)
{
	char	*str1;
	char	*str2;
	char	*new_str;
	int		i;

	str1 = get_first_segment(str);
	str1 = ft_strjoin(str1, tmp);
	i = -1;
	while (str[++i] != '$')
		;
	while (str[++i] && _char(str[i], str[i - 1]))
		;
	str2 = get_rest_of_string(str, i);
	new_str = ft_strjoin(str1, str2);
	free(str2);
	return (new_str);
}

char	*replace_variable(char *str)
{
	char	*new_str;
	char	*tmp;
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '$' && (str[i + 1] == '\0' || str[i + 1] == ' '))
			return (str);
	tmp = extract_variable_name(str);
	new_str = quote_variable(str, tmp);
	free(tmp);
	free(str);
	return (new_str);
}

char	*check_and_replace_variables(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\\' && str[i + 1] == '$')
			break ;
		if (str[i] == '$')
			str = replace_variable(str);
	}
	return (str);
}
