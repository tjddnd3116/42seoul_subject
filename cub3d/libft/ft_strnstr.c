/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:58:54 by hseong            #+#    #+#             */
/*   Updated: 2022/08/20 18:07:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;

	if (!*s2)
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *s2)
			if (!ft_strncmp(s1, s2, len))
				return ((char *)s1);
		++s1;
	}
	return (NULL);
}
