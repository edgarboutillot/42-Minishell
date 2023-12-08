/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:44:54 by edgarboutil       #+#    #+#             */
/*   Updated: 2023/11/16 13:29:48 by edgarboutil      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_signal_interrupt(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		printf("\n");
		display_prompt();
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		printf("\033[2D  ");
		printf("\033[2D");
		return ;
	}
}

int	initialize_signal_handling(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = (void *)handle_signal_interrupt;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	return (0);
}

void	toggle_control(int sig)
{
	struct termios	new;

	tcgetattr(0, &new);
	if (sig)
		new.c_lflag |= ECHOCTL;
	else
		new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &new);
}

void	handle_signal_quit(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_data->status = 0;
}

void	handle_ctrl_d(void)
{
	int		lvl;

	lvl = get_shell_level();
	if (lvl > 1)
		return (decrease_shell_level());
	free_minishell();
	printf("exit\n");
	exit(0);
}
