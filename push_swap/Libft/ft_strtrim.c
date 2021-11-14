/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:36:34 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:09:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char const *set, char c)
{
	int	index;

	index = 0;
	while (set[index] != c)
	{
		if (set[index] == '\0')
			return (0);
		index++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = -1;
	end = ft_strlen(s1) + 1;
	while (s1[++start])
	{
		if (ft_find(set, s1[start]) == 0)
			break ;
	}
	while (s1[--end - 1] && end > start)
		if (ft_find(set, s1[end - 1]) == 0)
			break ;
	tmp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &s1[start], end - start + 1);
	return (tmp);
}
