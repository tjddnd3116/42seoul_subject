/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:31:05 by soum              #+#    #+#             */
/*   Updated: 2022/01/06 15:45:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_info *info)
{
	int	philo_num;
	int	index;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (info->philo == NULL)
		return (0);
	index = 0;
	philo_num = info->num_philo;
	while (index < philo_num)
	{
		info->philo[index].info = info;
		info->philo[index].id = index + 1;
		info->philo[index].l_fork = index;
		info->philo[index].r_fork = (index + 1) % info->num_philo;
		info->philo[index].eat_count = 0;
		info->use_forks[index] = 0;
		index++;
	}
	return (1);
}

int	init_mutex(t_info *info)
{
	int	index;
	int	num_forks;

	index = 0;
	num_forks = info->num_philo;
	info->forks = (pthread_mutex_t *)malloc(\
			sizeof(pthread_mutex_t) * info->num_philo);
	if (info->forks == NULL)
		return (0);
	while (index < num_forks)
	{
		pthread_mutex_init(&info->forks[index], NULL);
		index++;
	}
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->all_eat_m, NULL);
	return (1);
}

int	init_info(t_info *info, int argc, char **argv)
{
	if (!(arg_check(argc, argv)))
		return (0);
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->num_eat = 0;
	if (argc == 6)
		info->num_eat = ft_atoi(argv[5]);
	if (info->num_philo <= 0 || info->num_philo > 200 || \
			info->time_die < 60 || info->time_eat < 60 || \
			info->time_sleep < 60 || info->num_eat < 0)
		return (0);
	info->use_forks = (int *)malloc(sizeof(int) * info->num_philo);
	if (info->use_forks == NULL)
		return (0);
	info->philo_idx = 0;
	info->philo_die = 0;
	info->all_eat_cnt = 0;
	info->all_eat = 0;
	if (!(init_philo(info)))
		return (0);
	if (!(init_mutex(info)))
		return (0);
	return (1);
}
