/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:36:28 by soum              #+#    #+#             */
/*   Updated: 2021/12/04 20:09:45 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void	print_message(t_philo *philo, char *str)
{
	long long	now_time;

	pthread_mutex_lock(&philo->info->print);
	if (!philo->info->philo_die)
	{
		now_time = now_time_ms();
		now_time = now_time - philo->info->start_time;
		printf("%lld %d %s", now_time, philo->id, str);
		now_time = now_time_ms();
		printf("| last_eat : %lld\n", now_time - philo->last_eat);
	}
	pthread_mutex_unlock(&philo->info->print);
}
