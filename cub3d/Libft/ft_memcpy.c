/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:37:26 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:06:17 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dst == src || n == 0)
		return (dst);
	while (index < n)
	{
		*(unsigned char *)(dst + index) = *(unsigned char *)(src + index);
		index++;
	}
	return (dst);
}
