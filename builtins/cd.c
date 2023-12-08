/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzentout <bzentout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:19 by bzentout          #+#    #+#             */
/*   Updated: 2023/12/05 15:01:14 by bzentout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"

void	new_env(char *path, int ac)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*path1;
	char	*path2;

	(void)ac;
	path1 = ft_strbjoin(path, "/.env2");
	path2 = ft_strbjoin(path, "/.env");
	fd = open(path1, O_RDONLY);
	fd2 = open(path2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = get_next_line(fd);
	while (line)
	{
		write(fd2, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	close(fd2);
	free(path1);
	free(path2);
}

char	*line_join(char *line, char *str, int option)
{
	free(line);
	if (!option)
	{
		line = ft_strbjoin("OLDPWD=", str);
		line = ft_strjoin(line, "\n");
		free(str);
	}
	else
	{
		line = ft_strbjoin("PWD=", str);
		line = ft_strjoin(line, "\n");
		free(str);
	}
	return (line);
}

void	copy_pwd(char *old, char *new, char *path)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*path1;
	char	*path2;

	path1 = ft_strbjoin(path, "/.env");
	path2 = ft_strbjoin(path, "/.env2");
	fd = open(path1, O_RDWR, 0644);
	fd2 = open(path2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "PWD=", 4) == 0)
			line = line_join(line, new, 1);
		if (ft_strncmp(line, "OLDPWD=", 7) == 0)
			line = line_join(line, old, 0);
		write(fd2, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	close(fd2);
	free(path1);
	free(path2);
}

char	*get_dir(char **av, char **ev)
{
	int		i;
	char	*line;

	i = -1;
	while (ev[++i])
	{
		if (ft_strncmp(ev[i], "HOME=", 5) == 0)
			line = ft_strdup(ev[i] + 5);
	}
	line = ft_strtrim(line, "\n");
	if (av[1] == NULL || (av[1][0] == '~' && av[1][1] == '\0'))
		return (line);
	if (av[1][0] == '~' && av[1][1] != '\0')
		return (ft_strjoin(line, av[1] + 1));
	free(line);
	line = ft_strdup(av[1]);
	return (line);
}

int	main(int ac, char **av, char **ev)
{
	int		fd;
	char	*old_pwd;
	char	*new_pwd;
	char	*path;
	char	*dir;

	path = get_base_path(ev);
	old_pwd = getcwd(NULL, 0);
	dir = get_dir(av, ev);
	if (chdir(dir) == -1)
		return (printf("minishell: cd: %s%s", dir, NOSUCH), free(dir), 1);
	new_pwd = getcwd(NULL, 0);
	path = ft_strjoin(path, "/.dir");
	fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0664);
	free(path);
	path = get_base_path(ev);
	write(fd, new_pwd, ft_strlen(new_pwd));
	close(fd);
	copy_pwd(old_pwd, new_pwd, path);
	new_env(path, ac);
	free(dir);
	free(path);
	erase_env(ev);
	return (0);
}
