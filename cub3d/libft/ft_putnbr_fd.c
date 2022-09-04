/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:23:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 15:45:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_num(int *n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char		buf[12];
	int			denom;
	size_t		size;

	size = 0;
	if (check_num(&n, fd))
		return ;
	else if (n < 0)
	{
		n *= -1;
		buf[size++] = '-';
	}
	denom = 1000000000;
	while (n / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		buf[size++] = n / denom + 48;
		n %= denom;
		denom /= 10;
	}
	write(fd, buf, size);
}

int	check_num(int *n, int fd)
{
	if (*n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else if (*n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}
