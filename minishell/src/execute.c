/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 04:10:03 by semin             #+#    #+#             */
/*   Updated: 2022/02/07 17:50:57 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	exec_extern(t_cmd *cmd, char **env)
{
	char	*command[6];
	int		i;

	command[0] = ft_strjoin("/bin/", cmd->cmdline[0]);
	command[1] = ft_strjoin("/usr/bin/", cmd->cmdline[0]);
	command[2] = ft_strjoin("/usr/local/bin/", cmd->cmdline[0]);
	command[3] = ft_strjoin("/usr/sbin/", cmd->cmdline[0]);
	command[4] = ft_strjoin("/sbin/", cmd->cmdline[0]);
	command[5] = 0;
	i = 0;
	execve(cmd->cmdline[0], cmd->cmdline, env);
	while (i < 5)
	{
		execve(command[i], cmd->cmdline, env);
		i++;
	}
	printf("minishell: %s: command not found\n", cmd->cmdline[0]);
	exit(127);
}

void	execute_extern(t_cmd *cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit(errno);
	if (pid == 0)
		exec_extern(cmd, env);
	else
	{
		waitpid(pid, &status, 0);
		g_status = status >> 8;
		free_envp(env);
	}
}

void	execute_cmd(t_data *data, t_cmd *cmd, t_env *env, int flag)
{
	g_status = 0;
	if (!ft_strcmp(cmd->cmdline[0], "export"))
		ft_export(cmd, env);
	else if (!ft_strcmp(cmd->cmdline[0], "cd"))
		ft_cd(cmd, env);
	else if (!ft_strcmp(cmd->cmdline[0], "unset"))
		ft_unset(cmd, env, data);
	else if (!ft_strcmp(cmd->cmdline[0], "exit"))
		ft_exit(cmd, flag, data);
	else
		execute_extern(cmd, make_envp(env));
}

void	execute_list(t_m_list *list, t_data *data, int b_stdin, int b_stdout)
{
	t_m_list	*cur;
	int			prev;

	cur = list;
	prev = 0;
	while (cur)
	{
		if (cur->content->flag == 1)
			create_child(cur, data, prev);
		else if (prev == 1)
			create_child(cur, data, prev);
		else
		{
			if (!rd_handler(cur->content))
				execute_cmd(data, cur->content, data->env, 0);
		}
		prev = cur->content->flag;
		if (prev == 0)
		{
			if (cur->content->out)
				dup2(b_stdin, 0);
			dup2(b_stdout, 1);
		}
		cur = cur->next;
	}
}

void	execute(t_data *data, t_m_list *list)
{
	int			stdin_dup;
	int			stdout_dup;

	stdin_dup = dup(0);
	stdout_dup = dup(1);
	execute_list(list, data, stdin_dup, stdout_dup);
	dup2(stdin_dup, 0);
	dup2(stdout_dup, 1);
	close(stdin_dup);
	close(stdout_dup);
}
