/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 16:34:09 by soum              #+#    #+#             */
/*   Updated: 2021/09/09 15:35:59 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_str_s(t_options *options, char *arg, char *tmp)
{
	int	prec;
	int	len;
	int	arg_len;

	arg_len = ft_strlen(arg);
	len = 0;
	prec = options->prec;
	if (prec == -1)
		tmp = ft_strdup(arg);
	else if (prec == 0)
		tmp = ft_strdup("");
	else if (prec > 0)
	{
		if (prec >= arg_len)
			tmp = ft_strdup(arg);
		else
		{
			tmp = (char *)malloc(sizeof(char) * prec);
			if (!tmp)
				return (NULL);
			ft_strlcpy(tmp, arg, prec + 1);
		}
	}
	return (tmp);
}

char	*put_str_d(t_options *options, int arg)
{
	int		len;
	char	*nbr;
	long	tmp;
	int		prec_len;

	tmp = arg;
	len = ft_nbrlen(tmp);
	prec_len = options->prec - len;
	nbr = nbrlloc(tmp, options, &len);
	if (!nbr)
		return (NULL);
	if (tmp < 0)
		tmp = -tmp;
	ft_itoa2(tmp, nbr, len, prec_len);
	put_pns(options, arg, nbr);
	return (nbr);
}

char	*put_str_u(t_options *options, unsigned int arg)
{
	int				len;
	char			*nbr;
	unsigned int	tmp;
	int				prec_len;

	tmp = arg;
	len = ft_nbrlen_u(tmp);
	prec_len = options->prec - len;
	nbr = nbrlloc(tmp, options, &len);
	if (!nbr)
		return (NULL);
	ft_itoa2(tmp, nbr, len, prec_len);
	put_pns(options, arg, nbr);
	return (nbr);
}

char	*put_str_x(t_options *options, unsigned int arg)
{
	int				len;
	char			*nbr;
	unsigned int	tmp;
	int				prec_len;

	tmp = arg;
	len = ft_nbrlen_x(tmp);
	prec_len = options->prec - len;
	nbr = nbrlloc(tmp, options, &len);
	if (tmp == 0 && nbr != NULL)
		nbr[len--] = '0';
	while (tmp != 0 && nbr != NULL)
	{
		nbr[len--] = HEXA[tmp % 16];
		tmp = tmp / 16;
	}
	while (prec_len-- > 0 && nbr != NULL)
		nbr[len--] = '0';
	if (options->hash == 1 && arg != 0 && nbr != NULL)
	{
		nbr[0] = '0';
		nbr[1] = 'x';
	}
	return (nbr);
}

char	*put_str_X(t_options *options, unsigned int arg)
{
	int				len;
	char			*nbr;
	unsigned int	tmp;
	int				prec_len;

	tmp = arg;
	len = ft_nbrlen_x(tmp);
	prec_len = options->prec - len;
	nbr = nbrlloc(tmp, options, &len);
	if (tmp == 0 && nbr != NULL)
		nbr[len--] = '0';
	while (tmp != 0 && nbr != NULL)
	{
		nbr[len--] = UHEXA[tmp % 16];
		tmp = tmp / 16;
	}
	while (prec_len-- > 0 && nbr != NULL)
		nbr[len--] = '0';
	if (options->hash == 1 && arg != 0 && nbr != NULL)
	{
		nbr[0] = '0';
		nbr[1] = 'X';
	}
	return (nbr);
}
