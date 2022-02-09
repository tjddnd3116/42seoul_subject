/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:14:30 by semin             #+#    #+#             */
/*   Updated: 2022/02/07 15:30:01 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	is_numeric(char *str)
{
	char	*p;

	p = str;
	while (*p)
	{
		if (*p < '0' || *p > '9')
			return (0);
		p++;
	}
	return (1);
}

void	ft_exit(t_cmd *cmd, int flag, t_data *data)
{
	int	status;

	if (flag)
		return ;
	printf("exit\n");
	if (!cmd->cmdline[1])
		status = g_status;
	else if (!is_numeric(cmd->cmdline[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", \
				cmd->cmdline[1]);
		status = 1;
	}
	else if (cmd->cmdline[2])
	{
		printf("minishell: exit: too many arguments\n");
		g_status = 1;
		return ;
	}
	else
		status = ft_atoi(cmd->cmdline[1]);
	free_cmd_list(data);
	free_env_list(data);
	exit(status);
}
