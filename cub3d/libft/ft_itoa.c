/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:04:39 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 20:08:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str_rev(char *s, size_t size);

char	*ft_itoa(int n)
{
	const char	*tab = "9876543210123456789";
	char		buf[12];
	size_t		size;
	int			temp;

	size = 0;
	temp = n;
	while (n)
	{
		buf[size] = tab[9 + n % 10];
		n /= 10;
		++size;
	}
	buf[size] = ('-') * (temp < 0) + ('0') * (temp == 0);
	buf[size + 1] = 0;
	ft_str_rev(buf, size + (temp <= 0));
	return (ft_strdup(buf));
}

static void	ft_str_rev(char *s, size_t size)
{
	size_t		idx;
	char		temp;

	idx = 0;
	--size;
	while (idx < size)
	{
		temp = s[idx];
		s[idx] = s[size];
		s[size] = temp;
		++idx;
		--size;
	}
}
