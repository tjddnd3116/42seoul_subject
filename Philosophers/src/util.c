/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:53:20 by soum              #+#    #+#             */
/*   Updated: 2021/12/03 18:29:40 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	init_info(t_info *info, int argc, char **argv)
{
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->num_eat = 0;
	if (argc == 6)
		info->num_eat = ft_atoi(argv[5]);
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_philo);
	gettimeofday(&info->start_time, NULL);
}
