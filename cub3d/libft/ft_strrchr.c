/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:03:33 by hseong            #+#    #+#             */
/*   Updated: 2021/11/17 15:59:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// different with linux.
char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	if (c == -1)
		return (NULL);
	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		++s;
	}
	if (!(char)c)
		ret = (char *)s;
	return (ret);
}
