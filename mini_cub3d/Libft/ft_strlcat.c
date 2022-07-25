/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:08:02 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:08:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t detsize)
{
	size_t	d_index;
	size_t	s_index;
	size_t	srclen;

	srclen = ft_strlen(src);
	d_index = 0;
	s_index = 0;
	while (dst[d_index] && d_index < detsize)
		d_index++;
	while (src[s_index] && (d_index + s_index + 1) < detsize)
	{
		dst[s_index + d_index] = src[s_index];
		s_index++;
	}
	if (d_index < detsize)
		dst[s_index + d_index] = '\0';
	return (d_index + srclen);
}
