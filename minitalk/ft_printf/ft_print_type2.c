/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:53:28 by soum              #+#    #+#             */
/*   Updated: 2021/09/08 14:32:31 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_d(int arg, t_options *options)
{
	int		len;
	char	*nbr;

	nbr = put_str_d(options, arg);
	if (!nbr)
		return (0);
	len = ft_strlen(nbr);
	if (options->width == 0)
		ft_putstr(nbr);
	else
	{
		if (options->minus == 1)
			len += print_minus(nbr, options, ft_strlen(nbr));
		else if (options->zero == 1)
		{
			if (arg < 0)
				len += print_zero_d(nbr, options, ft_strlen(nbr));
			else
				len += print_zero(nbr, options, ft_strlen(nbr));
		}
		else
			len += print_else(nbr, options, ft_strlen(nbr));
	}
	free(nbr);
	return (len);
}

int	printf_u(unsigned int arg, t_options *options)
{
	int		len;
	char	*nbr;
	int		nbr_len;

	nbr = put_str_u(options, arg);
	if (!nbr)
		return (0);
	nbr_len = ft_strlen(nbr);
	len = ft_strlen(nbr);
	if (options->prec >= 0)
		options->zero = 0;
	if (options->width == 0)
		ft_putstr(nbr);
	else
	{
		if (options->minus == 1)
			len += print_minus(nbr, options, nbr_len);
		else if (options->zero == 1)
			len += print_zero(nbr, options, nbr_len);
		else
			len += print_else(nbr, options, nbr_len);
	}
	free(nbr);
	return (len);
}

int	printf_x(unsigned int arg, t_options *options)
{
	int		len;
	char	*nbr;

	nbr = NULL;
	if (options->prec >= 0)
		options->zero = 0;
	if (options->type == 'x')
		nbr = put_str_x(options, arg);
	else if (options->type == 'X')
		nbr = put_str_X(options, arg);
	len = ft_strlen(nbr);
	if (options->width == 0)
		ft_putstr(nbr);
	else
	{
		if (options->minus == 1)
			len += print_minus(nbr, options, len);
		else if (options->zero == 1)
			len += print_zero(nbr, options, len);
		else
			len += print_else(nbr, options, len);
	}
	free(nbr);
	return (len);
}
