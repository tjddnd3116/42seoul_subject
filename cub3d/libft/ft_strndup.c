/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:27:17 by hseong            #+#    #+#             */
/*   Updated: 2022/05/11 15:28:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *src, size_t len)
{
	char	*dst;
	size_t	idx;

	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	dst[len] = 0;
	idx = 0;
	while (idx < len && src[idx])
	{
		dst[idx] = src[idx];
		++idx;
	}
	while (idx < len)
	{
		dst[idx] = 0;
		++idx;
	}
	return (dst);
}
