/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reparsing_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:00:49 by soum              #+#    #+#             */
/*   Updated: 2022/02/08 18:21:15 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	reparsing_env(t_data *data)
{
	t_m_list	*list;
	int			index;
	char		**cmdline;

	list = data->lstlast;
	while (list)
	{
		cmdline = list->content->cmdline;
		index = 0;
		while (cmdline[index])
		{
			cmdline[index] = cmdline_change(cmdline[index], data->env);
			index++;
		}
		list = list->next;
	}
}

char	*cmdline_change(char *cmdline, t_env *env)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(cmdline, '\'') && ft_strchr(cmdline, '"'))
		tmp = mixed_quote(cmdline, env);
	else if (ft_strchr(cmdline, '"'))
		tmp = double_quote(cmdline, env);
	else if (ft_strchr(cmdline, '\''))
		tmp = single_quote(cmdline);
	else if (ft_strchr(cmdline, '$'))
		tmp = double_quote(cmdline, env);
	else
		return (cmdline);
	free(cmdline);
	cmdline = NULL;
	return (tmp);
}
