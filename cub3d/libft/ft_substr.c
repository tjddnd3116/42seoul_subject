/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:24:15 by hseong            #+#    #+#             */
/*   Updated: 2021/11/11 03:57:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return empty string or NULL if start > strlen(s)?
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		idx;

	len += (ft_strlen(s) < start + len) * (ft_strlen(s) - start - len);
	if (ft_strlen(s) < start)
		len = 0;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	idx = 0;
	while (idx < len)
	{
		ret[idx] = s[start + idx];
		++idx;
	}
	return (ret);
}
