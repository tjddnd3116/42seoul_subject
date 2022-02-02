/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:00:16 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:03:02 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	ft_put_in(int n, char *tmp, int len)
{
	if (n == 0)
		tmp[0] = '0';
	while (n)
	{
		if (n == -2147483648)
		{
			tmp[len] = '8';
			len--;
			n = n / 10;
		}
		else if (n < 0)
		{
			tmp[0] = '-';
			n *= -1;
		}
		else
		{
			tmp[len] = n % 10 + '0';
			len--;
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		n_len;

	n_len = ft_nlen(n);
	if (n <= 0)
		n_len++;
	tmp = (char *)malloc(sizeof(char) * (n_len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[n_len] = '\0';
	n_len--;
	ft_put_in(n, tmp, n_len);
	return (tmp);
}
