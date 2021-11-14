/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minuszero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:56:41 by soum              #+#    #+#             */
/*   Updated: 2021/09/09 15:36:01 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_else(char *type, t_options *options, int type_len)
{
	int	len;

	len = 0;
	if (!type)
		return (0);
	while ((options->width) - type_len > 0)
	{
		write(1, " ", 1);
		len++;
		options->width = (options->width) - 1;
	}
	if (options->type == '%' || options->type == 'c')
		write(1, type, 1);
	else
		ft_putstr(type);
	return (len);
}

int	print_zero_d(char *type, t_options *options, int type_len)
{
	int	len;

	len = 0;
	if (!type)
		return (0);
	write(1, &type[0], 1);
	while ((options->width) - type_len > 0)
	{
		write(1, "0", 1);
		len++;
		options->width = (options->width) - 1;
	}
	if (options->type == '%' || options->type == 'c')
		write(1, type, 1);
	else
		ft_putstr(++type);
	return (len);
}

int	print_zero(char *type, t_options *options, int type_len)
{
	int	len;

	len = 0;
	if (!type)
		return (0);
	while ((options->width) - type_len > 0)
	{
		write(1, "0", 1);
		len++;
		options->width = (options->width) - 1;
	}
	if (options->type == '%' || options->type == 'c')
		write(1, type, 1);
	else
		ft_putstr(type);
	return (len);
}

int	print_minus(char *type, t_options *options, int type_len)
{
	int	len;

	len = 0;
	if (!type)
		return (0);
	if (options->type == '%' || options->type == 'c')
		write(1, type, 1);
	else
		ft_putstr(type);
	while ((options->width) - type_len > 0)
	{
		write(1, " ", 1);
		len++;
		options->width = (options->width) - 1;
	}
	return (len);
}

void	put_pns(t_options *options, long arg, char *nbr)
{
	if (options->plus == 1)
	{
		if (arg >= 0)
			nbr[0] = '+';
		else if (arg < 0)
			nbr[0] = '-';
	}
	else if (options->space == 1)
	{
		if (arg >= 0)
			nbr[0] = ' ';
		else if (arg < 0)
			nbr[0] = '-';
	}
	else if (arg < 0)
		nbr[0] = '-';
}
