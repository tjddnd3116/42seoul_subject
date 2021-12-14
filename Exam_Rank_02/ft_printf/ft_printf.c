#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_options
{
	char type;
	int	width;
	int prec;
}	t_options;

int	ft_putchar(char let)
{
	write(1, &let, 1);
	return (1);
}

void	init_options(t_options *options)
{
	options->type = 0;
	options->width = 0;
	options->prec = -1;
}

int	is_digit(char let)
{
	if (let >= '0' && let <= '9')
		return (1);
	else
		return (0);
}

void	check_flag(char *format, t_options *options, int i)
{
	if (is_digit(format[i]) && options->prec == -1)
		options->width = options->width * 10 + format[i] - 48;
	else if (format[i] == '.')
		options->prec = 0;
	else if (is_digit(format[i]))
		options->prec = options->prec * 10 + format[i] - 48;
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int str_len;
	char *tmp;
	int index;

	index = 0;
	str_len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * str_len + 1);
	while(index < str_len)
	{
		tmp[index] = str[index];
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}
void	ft_strlcpy(char *tmp, char *str, int len)
{
	int index;

	index = 0;
	while (index < len)
	{
		tmp[index] = str[index];
		index++;
	}
	tmp[index] = '\0';
}

char *put_prec_str(char *str, t_options *options, char *tmp)
{
	int prec;
	int str_len;

	prec = options->prec;
	str_len = ft_strlen(str);
	if (prec == -1)
	{
		tmp = ft_strdup(str);
	}
	else if (prec == 0)
		tmp = ft_strdup("");
	else if (prec > 0)
	{
		if (prec >= str_len)
			tmp = ft_strdup(str);
		else
		{
			tmp = (char *)malloc(sizeof(char) * prec);
			ft_strlcpy(tmp, str, prec);
		}
	}
	return (tmp);
}
void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

int	print_width_str(char *tmp, t_options *options, int len)
{
	int width;

	width = options->width;
	//printf("width : %d\n", width);
	if (width > len)
	{
		while (width - len > 0)
		{
			write(1, " ", 1);
			width--;
		}
		ft_putstr(tmp);
		return (options->width - len);
	}
	else
		ft_putstr(tmp);
	return (0);
}

int	print_s(char *str, t_options *options)
{
	int len;
	char *tmp;
	int width;
	int tmp_len;

	tmp = NULL;
	len = 0;
	width = options->width;
	if (str == NULL)
		str = "(null)";
	tmp = put_prec_str(str, options, tmp);
	len = ft_strlen(tmp);
	tmp_len = ft_strlen(tmp);
	if (width == 0)
		ft_putstr(tmp);
	else
		len += print_width_str(tmp, options, tmp_len);
	free(tmp);
	return (len);
}

/*
int	print_d(int num, t_options *options)
{
	int len;
	
	len = 0;
	return (len);
}

int print_x(unsigned int num, t_options *options)
{
	int len;

	len = 0;
	return (len);
}
*/
int	print_type(va_list ap, t_options *options)
{
	char type;
	int len;

	len = 0;
	type = options->type;
	if (type == 's')
		len = print_s(va_arg(ap, char *), options);
	//else if (type == 'd')
		//len = print_d(va_arg(ap, int), options);
	//else if (type == 'x')
		//len = print_x(va_arg(ap, unsigned int), options);
	return (len);
}
int	check_format(char *format, va_list ap)
{
	int len;
	int i;
	t_options *options;

	i = 0;
	options = malloc(sizeof(t_options));
	len = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		while (format[i] != '\0' && format[i] != '%')
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_options(options);
			while (format[++i] != '\0' && format[i] != 's' && format[i] != 'd' && format[i] != 'x')
				check_flag(format, options, i);
			options->type = format[i++];
			len += print_type(ap, options);
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	va_start(ap, format);
	len = check_format((char*)format, ap);
	va_end(ap);
	return (len);
}

int main(void)
{
	ft_printf("%5.3s", "abcd");
}
