/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 04:10:11 by semin             #+#    #+#             */
/*   Updated: 2022/02/10 15:17:38 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	print_export(t_env *env)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		printf("declare -x %s", cur->key);
		if (cur->value)
			printf("=\"%s\"\n", cur->value);
		else
			printf("\n");
		cur = cur->next;
	}
}

void	print_not_valid(char *cmd, char *str)
{
	printf("minishell: %s: `%s': not a valid identifier\n", cmd, str);
	g_status = 1;
}

t_env	*export_util(t_cmd *cmd, int i, t_env *env, t_env *cur)
{
	t_env	*newenv;

	if (ft_isalpha(cmd->cmdline[i][0]) || cmd->cmdline[i][0] == '_')
	{
		newenv = new_env(cmd->cmdline[1], env);
		if (newenv)
		{
			cur->next = newenv;
			return (cur->next);
		}
	}
	else
		print_not_valid("export", cmd->cmdline[i]);
	return (cur);
}

void	ft_export(t_cmd *cmd, t_env *env)
{
	t_env	*cur;
	int		i;

	cur = env;
	if (!cmd->cmdline[1])
		print_export(env);
	else
	{
		while (cur->next)
			cur = cur->next;
		i = 1;
		while (cmd->cmdline[i])
		{
			cur = export_util(cmd, i, env, cur);
			i++;
		}
	}
}
