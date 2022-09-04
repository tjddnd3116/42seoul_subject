/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:14:28 by hseong            #+#    #+#             */
/*   Updated: 2022/06/11 02:24:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (!n)
		return (0);
	str1 = s1;
	str2 = s2;
	while (--n && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
