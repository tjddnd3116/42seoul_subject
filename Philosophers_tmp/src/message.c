/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:29:09 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 19:30:49 by soum             ###   ########.fr       */
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
		printf("%lld %d %s\n", now_time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->info->print);
}
