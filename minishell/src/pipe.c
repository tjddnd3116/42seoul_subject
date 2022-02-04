/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:30:33 by semin             #+#    #+#             */
/*   Updated: 2022/02/01 23:23:02 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	child(int fd, t_cmd *cmd, t_env *env)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execute_cmd(cmd, env);
}

void	parent(int fd, t_m_list *list, t_env *env)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	execute(list, env);
}

void	set_pipe(t_m_list *list, t_env *env)
{
	pid_t	pid;
	t_cmd	*child_cmd;
	t_cmd	*parent_cmd;
	int		status;
	int		fd[2];

	child_cmd = list->content;
	parent_cmd = list->next->content;
	if (pipe(fd) < 0)
	{
		printf("pipe error");
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		// child
		close(fd[0]);
		child(fd[1], child_cmd, env);
		exit(0);
		//exit status
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		parent(fd[0], list->next, env);
	}
}
