/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:28:45 by soum              #+#    #+#             */
/*   Updated: 2021/05/28 20:46:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		s_len;

	find = (char)c;
	s_len = ft_strlen(s);
	while (s_len)
	{
		if (s[s_len] == find)
			return ((char *)(s + s_len));
		s_len--;
	}
	if (s[s_len] == find)
		return ((char *)s);
	return (NULL);
}
