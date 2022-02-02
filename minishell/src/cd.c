/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:52:14 by semin             #+#    #+#             */
/*   Updated: 2022/02/02 15:24:55 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

t_env	*find_env(char *key, t_env *env)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		if (!ft_strcmp(cur->key, key))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	add_env(t_env *env, char *key, char *value)
{
	t_env	*cur;
	char	*s;
	char	*envline;

	cur = env;
	while (cur->next)
		cur = cur->next;
	s = ft_strjoin(key, "=");
	envline = ft_strjoin(s, value);
	free(s);
	cur->next = new_env(envline);
	free(envline);
}

void	change_env(t_env *env, char *key, char *value)
{
	if (!env)
	{
		add_env(env, key, value);
		return ;
	}
	if (env->value)
		free(env->value);
	env->value = ft_strdup(value);
}

void	ft_chdir(char *dest, t_env *env)
{
	int		ret;
	char	*pwd;

	ret = -1;
	if (!ft_strcmp(dest, "-"))
	{
		if (!find_env("OLDPWD", env))
			printf("minishell: cd: OLDPWD not set\n");
		else
		{
			printf("%s\n", find_env("OLDPWD", env)->value);
			ret = chdir(find_env("OLDPWD", env)->value);
		}
	}
	else
		ret = chdir(dest);
	if (ret == -1 && ft_strcmp(dest, "-"))
		printf("minishell: cd: %s: Permission denied\n", dest);
	else
	{
		change_env(find_env("OLDPWD", env), "OLDPWD", find_env("PWD", env)->value);
		pwd = getcwd(0, 1024);
		change_env(find_env("PWD", env), "PWD", pwd);
		free(pwd);
	}
}

void	ft_cd(t_cmd *cmd, t_env *env)
{
	struct stat	filestat;
	int			stat_ret;

	if (!cmd->cmdline[1] || !ft_strcmp(cmd->cmdline[1], "~"))
		chdir(find_env("HOME", env)->value);
	else if (!ft_strcmp("-", cmd->cmdline[1]))
		ft_chdir(cmd->cmdline[1], env);
	else
	{
		stat_ret = stat(cmd->cmdline[1], &filestat);
		if (stat_ret == -1)
			printf("minishell: cd: %s: No such file or directory\n", \
					cmd->cmdline[1]);
		else if (!S_ISDIR(filestat.st_mode))
			printf("minishell: cd: %s: Not a directory\n", cmd->cmdline[1]);
		else
			ft_chdir(cmd->cmdline[1], env);
	}
}
