/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:41:40 by soum              #+#    #+#             */
/*   Updated: 2022/02/01 18:36:48 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	two_time_error(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == ';')
		{
			if (str[index + 1] != '\0' && str[index + 1] == ';')
				return (1);
		}
		else if (str[index] == '|')
		{
			if (str[index + 1] != '\0' && str[index + 1] == '|')
				return (1);
		}
		index++;
	}
	return (0);
}

int	quote_error(char *str)
{
	int	index;
	int	single_cnt;
	int	double_cnt;

	index = 0;
	single_cnt = 0;
	double_cnt = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			single_cnt++;
		else if (str[index] == '\"')
			double_cnt++;
		index++;
	}
	if (single_cnt % 2 || double_cnt % 2)
		return (1);
	return (0);
}

int	check_cmd(t_data *data)
{
	char	*str;

	str = data->cmd_set;
	if (str == NULL)
		return (1);
	if (two_time_error(str) == 1)
	{
		error_msg("shell : syntax error near unexpected token\n");
		return (1);
	}
	if (quote_error(str) == 1)
	{
		error_msg("shell : quote_error\n");
		return (1);
	}
	return (0);
}
