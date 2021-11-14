/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:04:57 by soum              #+#    #+#             */
/*   Updated: 2021/08/29 21:41:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_options(t_options *options)
{
	options->minus = 0;
	options->plus = 0;
	options->space = 0;
	options->zero = 0;
	options->hash = 0;
	options->dot = 0;
	options->width = 0;
	options->prec = -1;
	options->type = '\0';
}

void	check_flag(char *format, t_options *options, int i)
{
	if (format[i] == '-')
		options->minus = 1;
	else if (format[i] == '+')
		options->plus = 1;
	else if (format[i] == ' ')
		options->space = 1;
	else if (format[i] == '0' && options->width == 0 && options->prec == -1)
		options->zero = 1;
	else if (format[i] == '#')
		options->hash = 1;
	else if (ft_isdigit(format[i]) && options->prec == -1)
		options->width = options->width * 10 + format[i] - 48;
	else if (format[i] == '.')
		options->prec = 0;
	else if (ft_isdigit(format[i]) && options->prec >= 0)
		options->prec = options->prec * 10 + format[i] - 48;
}

int	check_type(va_list ap, t_options *options)
{
	int		len;
	char	type;

	len = 0;
	type = options->type;
	if (type == 'c')
		len = printf_c(va_arg(ap, int), options);
	else if (type == '%')
		len = printf_percent('%', options);
	else if (type == 's')
		len = printf_s(va_arg(ap, char *), options);
	else if (type == 'p')
		len = printf_p(va_arg(ap, unsigned long long), options);
	else if (type == 'd' || type == 'i')
	{
		if (options->prec >= 0)
			options->zero = 0;
		len = printf_d(va_arg(ap, int), options);
	}
	else if (type == 'u')
		len = printf_u(va_arg(ap, unsigned int), options);
	else if (type == 'x' || type == 'X')
		len = printf_x(va_arg(ap, unsigned int), options);
	return (len);
}

int	total_len(va_list ap, char *format)
{
	int			i;
	int			len;
	t_options	*options;

	i = 0;
	len = 0;
	options = malloc(sizeof(t_options) * 1);
	if (!options)
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_options(options);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				check_flag(format, options, i);
			options->type = format[i++];
			len += check_type(ap, options);
		}
	}
	free(options);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = total_len(ap, (char *)format);
	va_end(ap);
	return (len);
}
