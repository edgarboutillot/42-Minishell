/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:46:38 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/16 13:36:10 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>

typedef struct s_shell
{
	int					type;
	int					size;
	char				**words;
	struct s_shell		*next;
}						t_shell;

typedef struct s_slist
{
	int					type;
	char				*str;
	struct s_slist		*next;
}						t_slist;

typedef struct s_data
{
	int			ev_status;
	int			status;
	int			exit_status;
	int			old_fd[2];
	int			nl_error;
	int			first_call;
	int			command;
	int			redirect;
	int			nb_redirect;
	int			builtin;
	int			fd[2];
	int			cmd_error;
	int			ret;
	int			updater;
	char		*redir_in;
	char		*redir_out;
	char		*input;
	char		*line;
	char		*ev_dir;
	char		*ms_dir;
	char		**ev;
	char		**ev_path;
	char		*ev_user;
	t_slist		*s_list;
	t_shell		*shell_list;
}		t_data;

extern t_data	*g_data;

t_slist	*create_qlist_node(char *str, int type);
t_slist	*get_last_qlist_node(t_slist *lst);
void	add_node_to_qlist_back(t_slist **lst, t_slist *new);
void	clear_qlist(t_slist **lst);
t_shell	*create_s_node(char **content, int type, int size);
t_shell	*get_last_shell_node(t_shell *lst);
void	add_node_to_back(t_shell **lst, t_shell *new);
void	clear_shell_list(t_shell **lst);
void	handle_signal_quit(int sig);
void	toggle_control(int sig);
int		initialize_signal_handling(void);
void	handle_signal_interrupt(int signal, siginfo_t *info, void *context);
void	handle_ctrl_d(void);
char	*prepend_space_to_input(void);
void	display_command_list(void);
t_shell	*get_command_location(int i);
void	handle_exit_status(int option);
void	save_env_to_file(void);
void	display_prompt(void);
void	remove_file(char *path, char *file, char **ev);
int		get_shell_level(void);
void	decrease_shell_level(void);
void	free_minishell(void);
void	setup_minishell_environment(int ac, char **av, char **ev);
void	load_env_from_file(void);
char	*get_line(void);
void	parse_and_format_input(void);
void	process_new_line(void);
void	process_first_list(void);
void	copy_quoted_string(char *str, int *i, char type, int space);
int		count_quoted_string(int j, char type);
char	*join_strings(char *first_str, int *i);
char	*check_and_replace_variables(char *str);
char	*get_rest_of_string(char *str, int i);
char	*check_special_characters(char *str);
char	*get_environment_variable(char *str);
char	*get_first_segment(char *str);
void	process_second_list(void);
void	process_interpreted_strings(void);
void	execute_commands(void);
void	command_free(char *path, char **words);
void	new_command_init(void);
int		get_words_size(t_shell *tmp);
char	**add_after_redirections(t_shell *tmp, char **words);
char	**get_command_words(int i);
void	check_redirections(int i);
char	*check_builtin(char *str);
char	*path_loop(char *str, char **path_list, int i, int found);
char	*get_path(char *str);
void	path_error(char *str, char **words);
void	redirect(int option);
void	copy_redirections(t_shell *tmp);

#endif
