/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:20:33 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 17:28:02 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 && s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		tmp[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		tmp[s1_len + i] = s2[i];
	tmp[s1_len + i] = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	s1_len;
	int		index;

	index = 0;
	s1_len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (tmp == 0)
		return (NULL);
	while (s1[index])
	{
		tmp[index] = *(s1 + index);
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	index;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		tmp[index] = s[start + index];
		index++;
	}
	tmp[index] = 0;
	return (tmp);
}
