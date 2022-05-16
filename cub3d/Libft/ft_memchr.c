/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:30:35 by soum              #+#    #+#             */
/*   Updated: 2021/05/28 16:57:25 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	tmp;

	index = 0;
	tmp = (unsigned char)c;
	while (index < n)
	{
		if (*(unsigned char *)(s + index) == tmp)
			return ((void *)(s + index));
		index++;
	}
	return (NULL);
}
