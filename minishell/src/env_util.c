/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:45:17 by semin             #+#    #+#             */
/*   Updated: 2022/02/01 23:33:19 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	get_keylen(char *str)
{
	int	ret;

	ret = 0;
	while (*str && *str != '\'')
	{
		str++;
		ret++;
	}
	return (ret);
}

char	*replace_dollar(char *str, t_env *env)
{
	char	*c;
	int		key_len;
	char	*key;
	char	*ret;

	c = str;
	while (*c && *c != '$')
		c++;
	key_len = get_keylen(c + 1);
	key = ft_substr(str, c - str + 1, key_len);
	ret = ft_strdup(find_env(key, env)->value);
	free(key);
	return (ret);
}
