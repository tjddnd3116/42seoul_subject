/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:06:27 by soum              #+#    #+#             */
/*   Updated: 2021/09/11 15:27:43 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <stdio.h>

# define TYPE "csdiupxX%"
# define HEXA "0123456789abcdef"
# define UHEXA "0123456789ABCDEF"

typedef struct s_options
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		prec;
	char	type;
}	t_options;
void	init_options(t_options *options);
void	check_flag(char *format, t_options *options, int i);
int		check_type(va_list ap, t_options *options);
int		total_len(va_list ap, char *format);
int		ft_printf(const char *format, ...);
int		print_else(char *type, t_options *options, int type_len);
int		print_zero_d(char *type, t_options *options, int type_len);
int		print_zero(char *type, t_options *options, int type_len);
int		print_minus(char *type, t_options *options, int type_len);
void	put_pns(t_options *options, long arg, char *nbr);
int		printf_percent(char percent, t_options *options);
int		printf_c(int arg, t_options *options);
int		printf_s(char *arg, t_options *options);
int		printf_p(unsigned long long arg, t_options *options);
int		printf_d(int arg, t_options *options);
int		printf_u(unsigned int arg, t_options *options);
int		printf_x(unsigned int arg, t_options *options);
char	*put_str_s(t_options *options, char *arg, char *tmp);
char	*put_str_d(t_options *options, int arg);
char	*put_str_u(t_options *options, unsigned int arg);
char	*put_str_x(t_options *options, unsigned int arg);
char	*put_str_X(t_options *options, unsigned int arg);
int		ft_nbrlen(int arg);
int		ft_nbrlen_u(unsigned int arg);
int		ft_nbrlen_x(unsigned int arg);
void	ft_putstr(char *s);
int		ft_putchar(char s);
int		ft_nbrlen_ull(unsigned long long arg);
int		ft_nbrlen_l(long arg);
char	*nbrlloc(long tmp, t_options *options, int *len);
void	ft_itoa2(long tmp, char *nbr, int len, int prec_len);
char	*conv_hexa(unsigned long long arg);
#endif
