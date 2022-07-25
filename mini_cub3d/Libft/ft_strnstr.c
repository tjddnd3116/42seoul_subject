/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:37:01 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:09:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(const char *haystack, const char *needle, size_t i)
{
	size_t	index;

	index = 0;
	while (needle[index])
	{
		if (haystack[index + i] != needle[index])
			return (0);
		index++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (0);
	if (!*haystack)
		return (0);
	while (haystack[i] && (i <= (len - ft_strlen(needle))))
	{
		if (ft_find(haystack, needle, i) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
