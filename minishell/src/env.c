/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:31:41 by semin             #+#    #+#             */
/*   Updated: 2022/02/02 15:25:45 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

t_env	*new_env(char *envline)
{
	t_env	*new_env;
	char	**split_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	split_env = ft_split(envline, '=');
	new_env->key = ft_strdup(split_env[0]);
	if (split_env[1])
		new_env->value = ft_strdup(split_env[1]);
	else
		new_env->value = NULL;
	new_env->next = NULL;
	free(split_env[0]);
	if (split_env[1])
		free(split_env[1]);
	free(split_env);
	return (new_env);
}

int	get_envlen(char **env)
{
	int	ret;

	ret = 0;
	while (env[ret])
		ret++;
	return (ret);
}

t_env	*init_env(char **envp)
{
	t_env	*env;
	t_env	*cur;
	int		i;

	if (!envp[0])
		return (NULL);
	env = new_env(envp[0]);
	cur = env;
	i = 1;
	while (i < get_envlen(envp))
	{
		cur->next = new_env(envp[i]);
		cur = cur->next;
		i++;
	}
	return (env);
}

int	env_num(t_env *env)
{
	int		ret;
	t_env	*cur;

	ret = 0;
	cur = env;
	while (cur)
	{
		ret++;
		cur = cur->next;
	}
	return (ret);
}

char	**make_envp(t_env *env)
{
	char	**envp;
	char	*s;
	t_env	*cur;
	int		i;

	envp = (char **)malloc(sizeof(char *) * (env_num(env) + 1));
	i = 0;
	cur = env;
	while (i < env_num(env))
	{
		s = ft_strjoin(cur->key, "=");
		envp[i] = ft_strjoin(s, cur->value);
		free(s);
		i++;
		cur = cur->next;
	}
	envp[i] = NULL;
	return (envp);
}
