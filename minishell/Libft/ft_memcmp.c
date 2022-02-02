/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:38:41 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 18:48:00 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	tmp1;
	unsigned char	tmp2;
	size_t			index;

	index = 0;
	while (index < n)
	{
		tmp1 = *(unsigned char *)(s1 + index);
		tmp2 = *(unsigned char *)(s2 + index);
		if (tmp1 != tmp2)
			return (tmp1 - tmp2);
		index++;
	}
	return (0);
}
