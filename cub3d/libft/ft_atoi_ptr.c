/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:40:48 by hseong            #+#    #+#             */
/*   Updated: 2022/05/11 15:22:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LLONG_MAX (9223372036854775807LL)

int	ft_atoi_ptr(char **str_ptr)
{
	unsigned long long	num;
	unsigned long long	temp;
	int					ret;
	int					neg;
	const char			*str = *str_ptr;

	while (ft_isspace(*str))
		++str;
	neg = *str == '-';
	str += (neg || *str == '+');
	num = 0;
	temp = 0;
	while (ft_isdigit(*str) && temp <= num)
	{
		temp = num;
		num = 10 * num + *str++ - 48;
	}
	if (temp > num || num > LLONG_MAX)
		return ((int)(LLONG_MAX * !neg + (-LLONG_MAX - 1) * neg));
	ret = (1 - 2 * neg) * ((int)num);
	*str_ptr = (char *)str;
	return (ret);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}
