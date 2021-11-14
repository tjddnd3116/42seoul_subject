/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:12:06 by soum              #+#    #+#             */
/*   Updated: 2021/08/29 21:18:08 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int arg)
{
	int	len;

	len = 0;
	if (arg == 0)
		return (1);
	while (arg != 0)
	{
		arg = arg / 10;
		len++;
	}
	return (len);
}

int	ft_nbrlen_u(unsigned int arg)
{
	int	len;

	len = 0;
	if (arg == 0)
		return (1);
	while (arg != 0)
	{
		arg = arg / 10;
		len++;
	}
	return (len);
}

int	ft_nbrlen_x(unsigned int arg)
{
	int	len;

	len = 0;
	if (arg == 0)
		return (1);
	while (arg != 0)
	{
		arg = arg / 16;
		len++;
	}
	return (len);
}

void	ft_putstr(char *s)
{
	int	index;

	index = 0;
	if (!s)
		return ;
	while (s[index])
	{
		write(1, &s[index], 1);
		index++;
	}
}

int	ft_putchar(char s)
{
	int	len;

	len = 0;
	write(1, &s, 1);
	len++;
	return (len);
}
