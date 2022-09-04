/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:43:49 by hseong            #+#    #+#             */
/*   Updated: 2021/11/11 01:18:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revmemcpy(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src + len && dst > src)
		ft_revmemcpy(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

static void	*ft_revmemcpy(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	while (len--)
		d[len] = s[len];
	return (dst);
}
