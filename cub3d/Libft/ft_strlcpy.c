/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:01:03 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:08:36 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t detsize)
{
	size_t	len_src;
	size_t	index;

	index = 0;
	if ((dst == NULL) || (src == NULL))
		return (0);
	len_src = ft_strlen(src);
	if (detsize > 0)
	{
		while (src[index] && index < (detsize - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (len_src);
}
