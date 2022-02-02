/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 04:10:14 by semin             #+#    #+#             */
/*   Updated: 2022/02/02 15:28:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				index;
	const unsigned char	*s1_tmp;
	const unsigned char	*s2_tmp;

	index = 0;
	s1_tmp = (const unsigned char *)s1;
	s2_tmp = (const unsigned char *)s2;
	while (s1[index] || s2[index])
	{
		if (s1_tmp[index] != s2_tmp[index])
			return (s1_tmp[index] - s2_tmp[index]);
		index++;
	}
	return (0);
}

void	free_env(t_env **cur)
{
	free((*cur)->key);
	if ((*cur)->value)
		free((*cur)->value);
	free(*cur);
}

void	delete_env(t_env **env, char *key)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	prev = *env;
	while (cur)
	{
		if (!ft_strcmp(cur->key, key))
		{
			if (!(prev == cur))
			{
				prev->next = cur->next;
				free_env(&cur);
			}
			else
			{
				env = &cur->next;
				// 수정
				free_env(&cur);
			}
		}
		prev = cur;
		cur = cur->next;
	}
}

void	ft_unset(t_cmd *cmd, t_env *env)
{
	int	i;

	i = 1;
	while (cmd->cmdline[i])
	{
		if (ft_isalpha(cmd->cmdline[i][0]) || cmd->cmdline[i][0] == '_')
			delete_env(&env, cmd->cmdline[i]);
		else
			printf("minishell: unset: `%s\': not a valid identifier\n", \
					cmd->cmdline[i]);
		i++;
	}
}
