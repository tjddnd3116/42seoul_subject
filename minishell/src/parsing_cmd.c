/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:51:05 by soum              #+#    #+#             */
/*   Updated: 2022/02/02 16:18:17 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	put_in_cmd(t_data *data, char *cmd, char let)
{
	t_cmd		*cmd_data;
	t_m_list	*list;
	t_m_list	*new_list;

	list = data->lstlast;
	new_list = (t_m_list *)malloc(sizeof(t_m_list));
	cmd_data = (t_cmd *)malloc(sizeof(t_cmd));
	cmd_data->cmdline = ft_split(cmd, ' ');
	if (let == '|')
		cmd_data->flag = 1;
	else if (let == ';' || let == '\0')
		cmd_data->flag = 0;
	new_list->content = cmd_data;
	new_list->next = NULL;
	if (list == NULL)
		data->lstlast = new_list;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new_list;
	}
}

void	parsing_proc(t_data *data, char *tmp)
{
	int		i;
	int		j;
	char	*cmd;
	int		tmp_len;

	i = 0;
	j = 0;
	tmp_len = ft_strlen(tmp);
	while (i <= tmp_len)
	{
		if (tmp[i] == '\0' && (tmp[i -1] == ';' || tmp[i -i] == '|'))
			break;
		if (tmp[i] == ';' || tmp[i] == '|' || tmp[i] == '\0')
		{
			cmd = (char *)malloc(sizeof(char) * (i - j + 1));
			ft_strlcpy(cmd, tmp + j, i - j + 1);
			j = i + 1;
			put_in_cmd(data, cmd, tmp[i]);
			free(cmd);
		}
		i++;
	}
}

void	parsing(t_data *data)
{
	char	*tmp;

	tmp = data->cmd_set;
	parsing_proc(data, tmp);
	execute_list(data->lstlast, data->env);
}
