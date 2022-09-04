/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:21:59 by hseong            #+#    #+#             */
/*   Updated: 2021/11/11 02:28:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = s;
	if (!n)
		return (NULL);
	while (--n && *ptr != (unsigned char)c)
		++ptr;
	if (*ptr != (unsigned char)c)
		return (NULL);
	return ((void *)ptr);
}
