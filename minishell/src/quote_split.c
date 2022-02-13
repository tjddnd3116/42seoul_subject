/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:07:20 by soum              #+#    #+#             */
/*   Updated: 2022/02/13 13:49:54 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	sep_cnt_quote(char *cmd, char c)
{
	int	cnt;
	int	index;

	cnt = 0;
	index = 0;
	while (cmd[index])
	{
		if (cmd[index] == '"')
			cnt += quote_index(cmd, &index);
		else if (cmd[index] == '\'')
			cnt += quote_index(cmd, &index);
		else if (cmd[index] != c)
			cnt += quote_index(cmd, &index);
		if (cmd[index] == ' ')
			index++;
	}
	return (cnt);
}

void	putin(char *cmd, char *cmdline, int from, int i)
{
	int	index;

	index = 0;
	while (from < i)
	{
		cmdline[index] = cmd[from];
		index++;
		from++;
	}
	cmdline[index] = '\0';
}

void	sep_cmdline(char *cmd, char c, char **cmdline)
{
	int	index;
	int	i;
	int	from;

	index = 0;
	i = 0;
	from = 0;
	while (i < (int)ft_strlen(cmd))
	{
		if (cmd[i] == '"')
			cmdline[index++] = put_in_cmdline(cmd, &i);
		else if (cmd[i] == '\'')
			cmdline[index++] = put_in_cmdline(cmd, &i);
		else if (cmd[i] != c)
			cmdline[index++] = put_in_cmdline(cmd, &i);
		if (cmd[i] == ' ')
			i++;
	}
}

char	**quote_split(char *cmd, char c)
{
	char	**cmdline;
	int		sep_cnt;

	sep_cnt = sep_cnt_quote(cmd, c);
	cmdline = (char **)malloc(sizeof(char *) * (sep_cnt + 1));
	if (!cmdline)
		return (NULL);
	sep_cmdline(cmd, c, cmdline);
	cmdline[sep_cnt] = NULL;
	return (cmdline);
}
