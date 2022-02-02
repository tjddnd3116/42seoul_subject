/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:14:30 by semin             #+#    #+#             */
/*   Updated: 2022/02/02 15:26:43 by soum             ###   ########.fr       */
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

void	ft_exit(t_cmd *cmd)
{
	int	status;

	printf("exit\n");
	if (!cmd->cmdline[1])
		exit(0);
	else if (!is_numeric(cmd->cmdline[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", \
				cmd->cmdline[1]);
		exit(1);
	}
	else if (cmd->cmdline[2])
		printf("minishell: exit: too many arguments\n");
	else
	{
		status = ft_atoi(cmd->cmdline[1]);
		exit(status);
	}
}
