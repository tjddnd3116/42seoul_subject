/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:17:08 by soum              #+#    #+#             */
/*   Updated: 2022/02/12 22:15:20 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len;
	char	*tmp;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	ft_strlcpy(tmp + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (tmp);
}

t_env	*replace_env(char **split_env, t_env *findenv)
{
	if (split_env[1])
	{
		free(findenv->value);
		findenv->value = ft_strdup(split_env[1]);
		free(split_env[0]);
		free(split_env[1]);
		free(split_env);
	}
	else
	{
		free(split_env[0]);
		free(split_env[1]);
		free(split_env);
	}
	return (NULL);
}

void	join_path(t_cmd *cmd, char **path, char **command)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		command[i] = ft_strjoin(tmp, cmd->cmdline[0]);
		free(tmp);
		i++;
	}
	command[i] = 0;
}

void	reset_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
