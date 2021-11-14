/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:30:40 by soum              #+#    #+#             */
/*   Updated: 2021/09/08 12:41:04 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen_ull(unsigned long long arg)
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

int	ft_nbrlen_l(long arg)
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

char	*nbrlloc(long tmp, t_options *options, int *len)
{
	char	*nbr;
	char	type;

	type = options->type;
	nbr = NULL;
	if (options->prec == 0 && tmp == 0)
		return (ft_strdup(""));
	if (*len < options->prec)
		*len += options->prec - *len;
	if ((options->plus == 1 || options->space == 1 || tmp < 0) \
			&& (type == 'd' || type == 'i' || type == 'u'))
		(*len)++;
	if (options->hash == 1 && tmp != 0 && \
			(type == 'x' || type == 'X'))
		(*len) += 2;
	nbr = (char *)malloc(sizeof(char) * *len + 1);
	if (!nbr)
		return (NULL);
	nbr[(*len)--] = '\0';
	return (nbr);
}

void	ft_itoa2(long tmp, char *nbr, int len, int prec_len)
{
	if (tmp == 0)
		nbr[len--] = '0';
	while (tmp != 0)
	{
		nbr[len--] = tmp % 10 + 48;
		tmp = tmp / 10;
	}
	while (prec_len-- > 0)
		nbr[len--] = '0';
}

char	*conv_hexa(unsigned long long arg)
{
	char				*result;
	int					len;
	unsigned long long	tmp;
	int					minus;

	tmp = arg;
	len = ft_nbrlen_ull(tmp);
	len += 2;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len--] = '\0';
	result[0] = '0';
	result[1] = 'x';
	if (arg == 0)
		result[2] = '0';
	while (arg != 0)
	{
		minus = arg % 16;
		result[len--] = HEXA[minus];
		arg = arg / 16;
	}
	return (result);
}
