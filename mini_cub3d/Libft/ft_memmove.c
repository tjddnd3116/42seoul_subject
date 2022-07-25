/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:57:42 by soum              #+#    #+#             */
/*   Updated: 2021/05/28 16:26:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*d_tmp;
	unsigned char	*s_tmp;

	d_tmp = (unsigned char *)dst;
	s_tmp = (unsigned char *)src;
	index = -1;
	if (d_tmp == s_tmp || len == 0)
		return (dst);
	if (d_tmp < s_tmp)
	{
		while (++index < len)
			d_tmp[index] = s_tmp[index];
	}
	else
	{
		while (++index < len)
			d_tmp[len - 1 - index] = s_tmp[len - 1 - index];
	}
	return (dst);
}
