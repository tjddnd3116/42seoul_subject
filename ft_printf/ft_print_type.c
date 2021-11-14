/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:09:26 by soum              #+#    #+#             */
/*   Updated: 2021/09/08 13:05:41 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_percent(char percent, t_options *options)
{
	int		len;
	char	*type;

	type = &percent;
	len = 1;
	if (options->width == 0)
		write(1, &percent, 1);
	else
	{
		if (options->minus == 1)
			len += print_minus(type, options, 1);
		else
			len += print_else(type, options, 1);
	}
	return (len);
}

int	printf_c(int arg, t_options *options)
{
	int		len;
	char	let;
	char	*type;

	let = (char)arg;
	type = &let;
	len = 1;
	if (options->width == 0)
		write(1, type, 1);
	else
	{
		if (options->minus == 1)
			len += print_minus(type, options, 1);
		else
			len += print_else(type, options, 1);
	}
	return (len);
}

int	printf_s(char *arg, t_options *options)
{
	int		len;
	char	*tmp;
	int		tmp_len;

	tmp = NULL;
	if (arg == NULL)
		arg = "(null)";
	tmp = put_str_s(options, arg, tmp);
	tmp_len = ft_strlen(tmp);
	len = ft_strlen(tmp);
	if (options->width == 0)
		ft_putstr(tmp);
	else
	{
		if (options->minus == 1)
			len += print_minus(tmp, options, tmp_len);
		else if (options->zero == 1)
			len += print_zero(tmp, options, tmp_len);
		else
			len += print_else(tmp, options, tmp_len);
	}
	free(tmp);
	return (len);
}

int	printf_p(unsigned long long arg, t_options *options)
{
	int		len;
	char	*hexa;
	int		hexa_len;

	hexa = conv_hexa(arg);
	hexa_len = ft_strlen(hexa);
	len = hexa_len;
	if (options->width == 0)
		ft_putstr(hexa);
	else
	{
		if (options->minus == 1)
			len += print_minus(hexa, options, hexa_len);
		else
			len += print_else(hexa, options, hexa_len);
	}
	free(hexa);
	return (len);
}
