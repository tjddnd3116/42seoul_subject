/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:03:40 by soum              #+#    #+#             */
/*   Updated: 2022/02/13 00:25:44 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	key_len(char *str)
{
	int	len;

	len = 0;
	if (*str == '?')
		return (1);
	while (*str && *str != '$' && *str != ' ' \
			&& *str != '"' && *str != '\'' && ft_isalpha(*str))
	{
		str++;
		len++;
	}
	return (len);
}

char	*dollar_sign(char *cmdline, t_env *env)
{
	char	*new_cmdline;

	new_cmdline = double_quote(cmdline, env);
	return (new_cmdline);
}

char	*mixed_quote(char *cmdline, t_env *env)
{
	char	*new_cmdline;

	if (ft_strchr(cmdline, '\'') - cmdline < ft_strchr(cmdline, '"') - cmdline)
		new_cmdline = single_quote(cmdline);
	else
		new_cmdline = double_quote(cmdline, env);
	return (new_cmdline);
}

char	*double_quote(char *cmdline, t_env *env)
{
	char	*new_cmdline;
	char	let[2];
	int		index;
	char	*repl;

	index = -1;
	let[1] = 0;
	new_cmdline = ft_calloc(1, sizeof(char));
	while (cmdline[++index])
	{
		let[0] = cmdline[index];
		if (cmdline[index] == '$')
		{
			repl = replace_dollar(&cmdline[index], env);
			if (repl)
			{
				new_cmdline = ft_strjoin_free(new_cmdline, repl);
				free(repl);
			}
			index += key_len(&cmdline[index + 1]);
		}
		else if (cmdline[index] != '"')
			new_cmdline = ft_strjoin_free(new_cmdline, let);
	}
	return (new_cmdline);
}

char	*single_quote(char *cmdline)
{
	char	*new_cmdline;
	char	let[2];
	int		index;

	index = 0;
	let[1] = 0;
	new_cmdline = (char *)malloc(sizeof(char));
	new_cmdline[0] = '\0';
	while (cmdline[index])
	{
		if (cmdline[index] != '\'')
		{
			let[0] = cmdline[index];
			new_cmdline = ft_strjoin_free(new_cmdline, let);
		}
		index++;
	}
	return (new_cmdline);
}
