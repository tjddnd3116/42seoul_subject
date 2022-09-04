/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:57 by hseong            #+#    #+#             */
/*   Updated: 2022/06/06 01:52:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_addr(void *addr);
static void	print_hex(unsigned char hex);
static void	print_hexcontent(void *addr, size_t len);
static void	print_content(void *addr, size_t len);

void	*ft_print_memory(void *addr, size_t size)
{
	unsigned char	*ptr;
	size_t			idx;
	size_t			sub_len;

	if (addr == 0 || size == 0)
		return (0);
	ptr = addr;
	idx = 0;
	while (idx < size)
	{
		sub_len = 16 * (size >= idx + 16) + (size - idx) * (size < idx + 16);
		print_addr(ptr);
		print_hexcontent(ptr, sub_len);
		print_content(ptr, sub_len);
		write(1, "\n", 1);
		ptr += 16;
		idx += 16;
	}
	return (addr);
}

void	print_addr(void	*addr)
{
	int				bit;
	unsigned char	hex;
	unsigned char	*ptr;

	ptr = addr;
	bit = 60;
	while (bit >= 0)
	{
		hex = (unsigned char)(((unsigned long long int)ptr >> bit) & 15);
		print_hex(hex);
		bit -= 4;
	}
	write(1, ": ", 2);
}

// hex range should be [0, 15]
void	print_hex(unsigned char hex)
{
	hex = (hex > 9) * ('a' + hex - 10) + (hex <= 9) * ('0' + hex);
	write(1, &hex, 1);
}

void	print_hexcontent(void *addr, size_t len)
{
	size_t			idx;
	unsigned char	*ptr;

	ptr = addr;
	idx = 0;
	while (idx < len)
	{
		print_hex(*ptr >> 4);
		print_hex(*ptr & 15);
		write(1, " ", idx % 2);
		++idx;
		++ptr;
	}
	while (idx < 16)
		write(1, "   ", 2 + idx++ % 2);
}

// size should be valid
void	print_content(void *addr, size_t len)
{
	unsigned char	*ptr;

	ptr = addr;
	while (len)
	{
		if (*ptr < 32 || *ptr > 126)
			write(1, ".", 1);
		else
			write(1, ptr, 1);
		++ptr;
		--len;
	}
}
