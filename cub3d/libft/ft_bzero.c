/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:36:54 by hseong            #+#    #+#             */
/*   Updated: 2022/01/24 21:55:23 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	t_word			*word;
	t_word			zero;
	int				idx;

	ptr = (unsigned char *)s;
	idx = n % (8 * WORD_BYTES);
	while (idx--)
		*ptr++ = 0;
	n /= 8 * WORD_BYTES;
	word = (t_word *)ptr;
	idx = 0;
	while (idx < WORD_BYTES)
		zero.byte[idx++] = 0;
	while (n--)
		*word++ = zero;
}
