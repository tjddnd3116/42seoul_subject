/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:36:28 by soum              #+#    #+#             */
/*   Updated: 2021/12/09 19:45:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_all_last_eat(t_info *info)
{
	int index;
	long long last_eat;

	index = 0;
	while (index < info->num_philo)
	{
		last_eat = info->philo[index].last_eat - info->start_time;
		printf("[%d] philo last eat :%lld\n", index + 1, last_eat);
		index++;
	}
	printf("last time : %lld\n", now_time_ms() - info->start_time);
}

void	print_message(t_philo *philo, char *str)
{
	long long	now_time;

	pthread_mutex_lock(&philo->info->print);
	if (!philo->info->philo_die)
	{
		now_time = now_time_ms();
		now_time = now_time - philo->info->start_time;
		printf("%lld %d %s\n", now_time, philo->id, str);
		//printf(" | last_eat : %lld\n", philo->last_eat - philo->info->start_time);
	}
	pthread_mutex_unlock(&philo->info->print);
}
