/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:11:04 by soum              #+#    #+#             */
/*   Updated: 2022/02/12 22:05:43 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	init_cmd(t_cmd *cmd_data, char *cmd, char let)
{
	cmd_data->out = 0;
	if (ft_strrchr(cmd, '>'))
		cmd_data->out = 1;
	if (let == '|')
		cmd_data->flag = 1;
	else if (let == ';' || let == '\0')
		cmd_data->flag = 0;
}

void	init_struct(t_data *data, char **envp)
{
	data->lstlast = NULL;
	data->env = init_env(envp);
	setting_signal();
}

void	sigint_handler(int signal)
{
	pid_t	pid;
	int		status;

	(void)signal;
	pid = waitpid(-1, &status, WNOHANG);
	if (pid != -1)
	{
		g_status = 1;
		printf("^C\n");
		return ;
	}
	printf("minishell$ \n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	g_status = 130;
}

void	sigquit_handler(int signal)
{
	pid_t	pid;
	int		status;

	(void)signal;
	pid = waitpid(-1, &status, WNOHANG);
	if (pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
	printf("^\\Quit: 3\n");
	g_status = 131;
}

void	setting_signal(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
