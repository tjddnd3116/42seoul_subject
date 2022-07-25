/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:09:58 by soum              #+#    #+#             */
/*   Updated: 2021/05/06 13:15:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned char	ctmp;
	size_t			index;

	index = 0;
	tmp = b;
	ctmp = (unsigned char)c;
	while (index < len)
	{
		tmp[index] = ctmp;
		index++;
	}
	return (b);
}
