/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:21:20 by hseong            #+#    #+#             */
/*   Updated: 2022/09/04 14:46:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WORD_BYTES (16)

typedef unsigned long long int	t_uint64;

typedef struct s_word
{
	unsigned long long int	byte[WORD_BYTES];
}			t_word;

static void	set_word(int c, t_word *num);

// int32 0A0B0C0D	> i [0A], i+1 [0B], i+2 [0C], i+3[0D]
// big endian		: msb is at lower address.
// int32 0A0B0C0D	> i [0D], i+1 [0C], i+2 [0B], i+3[0A]
// little endian	: lsb is at lower address.
void	*ft_memset(void *b, int c, t_uint64 len)
{
	unsigned char	*ptr;
	t_word			*word;
	t_word			num;
	t_uint64		idx;

	ptr = (unsigned char *)b;
	idx = len % (8 * WORD_BYTES);
	while (idx--)
		*ptr++ = (unsigned char)c;
	len /= (8 * WORD_BYTES);
	word = (t_word *)ptr;
	idx = 0;
	set_word(c, &num);
	while (idx < len)
		word[idx++] = num;
	return (b);
}

void	set_word(int c, t_word *num)
{
	t_uint64	idx;
	t_uint64	long_c;

	long_c = (t_uint64)c;
	long_c = long_c + (long_c << 32);
	idx = 0;
	while (idx < WORD_BYTES)
		num->byte[idx++] = long_c;
}
