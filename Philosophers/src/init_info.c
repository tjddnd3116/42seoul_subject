/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:15:17 by soum              #+#    #+#             */
/*   Updated: 2021/12/10 16:11:51 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philo(t_info *info)
{
	int	philo_num;
	int	index;
	
	index = 0;
	philo_num = info->num_philo;
	while (index < philo_num)
	{
		info->philo[index].info = info;
		info->philo[index].id = index + 1;
		info->philo[index].l_fork = index;
		info->philo[index].r_fork = (index + 1) % info->num_philo;
		if (index == philo_num - 1 && index != 0)
			info->philo[index].r_fork = 1;
		info->philo[index].eat_count = 0;
		info->philo[index].last_eat = 0;
		index++;
	}
}

void	init_mutex(t_info *info)
{
	int	index;
	int	num_forks;

	index = 0;
	num_forks = info->num_philo;
	while (index < num_forks)
	{
		pthread_mutex_init(&info->forks[index], NULL);
		index++;
	}
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->time_m, NULL);
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
	info->forks = (pthread_mutex_t *)malloc(\
			sizeof(pthread_mutex_t) * info->num_philo);
	info->start_time = now_time_ms();
	info->philo_idx = 0;
	info->philo_die = 0;
	init_philo(info);
	init_mutex(info);
}
