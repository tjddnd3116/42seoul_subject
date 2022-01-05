/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:11:17 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 19:54:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	now_time_ms(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

int	ft_atoi(const char *str)
{
	int			index;
	int			sign;
	long long	result;

	sign = 1;
	index = 0;
	result = 0;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10;
		result += str[index] - '0';
		index++;
	}
	return (result * sign);
}

int	arg_check(int argc, char **argv)
{
	int	arg_cnt;
	int	index;

	arg_cnt = 1;
	while (arg_cnt < argc)
	{
		index = 0;
		while (argv[arg_cnt][index])
		{
			if (argv[arg_cnt][index] >= '0' && argv[arg_cnt][index] <= '9')
				index++;
			else
				return (0);
		}
		arg_cnt++;
	}
	return (1);
}
