/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:30:13 by soum              #+#    #+#             */
/*   Updated: 2022/02/02 15:59:40 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	free_env_list(t_data *data)
{
	t_env *env;

	env = data->env;
}

void	free_cmd_data(t_cmd *content)
{
	t_cmd	*data;
	int		index;

	index = 0;
	data = content;
	while (data->cmdline[index])
	{
		free(data->cmdline[index]);
		index++;
	}
	free(data->cmdline[index]);
	free(data->cmdline);
	data->cmdline = NULL;
	free(content);
}

void	free_cmd_list(t_data *data)
{
	t_m_list	*tmp_list;
	t_m_list	*list;

	list = data->lstlast;
	tmp_list = data->lstlast;
	while (list)
	{
		free_cmd_data(list->content);
		tmp_list = list->next;
		free(list);
		list = NULL;
		list = tmp_list;
	}
	data->lstlast = NULL;
	free(data->cmd_set);
}
