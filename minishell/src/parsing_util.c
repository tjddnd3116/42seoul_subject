/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:11:52 by soum              #+#    #+#             */
/*   Updated: 2022/02/12 14:47:30 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	quote_index(char *cmd, char let, int *i)
{
	(void)let;
	while (cmd[*i] && cmd[*i] != ' ')
	{
		if (cmd[*i] == '"')
			*i = ft_strchr(&cmd[*i + 1], '"') - cmd + 1;
		else if (cmd[*i] == '\'')
			*i = ft_strchr(&cmd[*i + 1], '\'') - cmd + 1;
		else
			(*i)++;
	}
	/** (*index)++; */
	/** while (cmd[*index] && cmd[*index] != let) */
	/**     (*index)++; */
	/** while (cmd[*index] && cmd[*index] != ' ') */
	/**     (*index)++; */
	return (1);
}

char	*new_put_in_cmdline(char *cmd, int *i)
{
	int from;
	char *cmdline;

	from = *i;
	while (cmd[*i] && cmd[*i] != ' ')
	{
		if (cmd[*i] == '"')
			*i = ft_strchr(&cmd[*i + 1], '"') - cmd + 1;
		else if (cmd[*i] == '\'')
			*i = ft_strchr(&cmd[*i + 1], '\'') - cmd + 1;
		else
			(*i)++;
	}
	cmdline = (char *)malloc((*i - from + 1) * sizeof(char));
	putin(cmd, cmdline, from, (*i));
	return (cmdline);
}

/** char	*put_in_cmdline(char *cmd, char let, int *i) */
/** { */
/**     int		from; */
/**     char	*cmdline; */
/**  */
/**     from = *i; */
/**     (*i)++; */
/**     while (cmd[*i] && cmd[*i] != let) */
/**         (*i)++; */
/**     while (cmd[*i] && cmd[*i] != ' ') */
/**         (*i)++; */
/**     cmdline = (char *)malloc((*i - from + 1) * sizeof(char)); */
/**     putin(cmd, cmdline, from, (*i + 1)); */
/**     printf("$%s$\n", cmdline); */
/**     return (cmdline); */
/** } */
/**  */
/** char	*put_in_cmdline_normal(char *cmd, char let, int *i) */
/** { */
/**     int		from; */
/**     char	*cmdline; */
/**  */
/**     from = *i; */
/**     while (cmd[*i] && cmd[*i] != let) */
/**         (*i)++; */
/**     cmdline = (char *)malloc((*i - from + 1) * sizeof(char)); */
/**     putin(cmd, cmdline, from, *i); */
/**     return (cmdline); */
/** } */

int	find_quote_match(char *tmp, int i)
{
	char	*match_ptr;

	if (tmp[i] == '"')
	{
		match_ptr = ft_strchr(&tmp[i + 1], '"');
		if (match_ptr == NULL)
			return (-1);
		else
			i = match_ptr - tmp + 1;
	}
	else if (tmp[i] == '\'')
	{
		match_ptr = ft_strchr(&tmp[i + 1], '\'');
		if (match_ptr == NULL)
			return (-1);
		else
			i = match_ptr - tmp + 1;
	}
	else
		i++;
	return (i);
}
