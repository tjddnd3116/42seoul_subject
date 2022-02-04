/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:30:13 by soum              #+#    #+#             */
/*   Updated: 2022/02/04 20:11:02 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void 	free_envp(char **env)
{
	int index;

	index = 0;
	while(env[index])
	{
		free(env[index]);
		index++;
	}
	free(env[index]);
	free(env);
}

void	free_env_list(t_data *data)
{
	t_env *env;
	t_env *tmp_env;

	env = data->env;
	while (env)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		tmp_env = env->next;
		free(env);
		env = NULL;
		env = tmp_env;
	}
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
