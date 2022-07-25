/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:19:46 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 18:47:40 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	tmp;

	index = 0;
	while (index < n)
	{
		tmp = *(unsigned char *)(src + index);
		*(unsigned char *)(dst + index) = tmp;
		if (tmp == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
