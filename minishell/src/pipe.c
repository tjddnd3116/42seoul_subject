/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:16:31 by soum              #+#    #+#             */
/*   Updated: 2022/02/08 19:16:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	child(t_m_list *list, t_data *data)
{
	t_cmd	*cmd;
	int		err;

	cmd = list->content;
	err = rd_handler(cmd);
	close(cmd->fd[0]);
	if (cmd->flag == 1 && !cmd->out)
	{
		dup2(cmd->fd[1], STDOUT_FILENO);
		close(cmd->fd[1]);
	}
	if (!err)
		execute_cmd(data, cmd, data->env, 1);
	exit(g_status);
}

void	create_child(t_m_list *list, t_data *data, int prev)
{
	pid_t	pid;
	int		status;

	if (pipe(list->content->fd) < 0)
	{
		printf("pipe error");
		return ;
	}
	if (prev == 1)
		dup2(200, STDIN_FILENO);
	pid = fork();
	if (pid == 0)
		child(list, data);
	else
	{
		waitpid(pid, &status, 0);
		g_status = status >> 8;
		close(list->content->fd[1]);
		if (list->content->flag == 1)
			dup2(list->content->fd[0], 200);
		close(list->content->fd[0]);
	}
}
