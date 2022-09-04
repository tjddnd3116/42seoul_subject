/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:38:37 by hseong            #+#    #+#             */
/*   Updated: 2021/11/08 23:48:21 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		ret;

	ret = 0;
	while (src[ret])
		++ret;
	if (!size)
		return (ret);
	while (*src && size - 1)
	{
		*dest++ = *src++;
		--size;
	}
	*dest = 0;
	return (ret);
}
