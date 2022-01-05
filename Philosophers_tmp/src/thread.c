/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:30:49 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 19:47:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_thread(t_info *info)
{
	int	num_philo;
	int	index;

	index = 0;
	num_philo = info->num_philo;
	while (index < num_philo)
	{
		pthread_join(info->philo[index].thread, NULL);
		index++;
	}
}

void	main_thread(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < info->num_philo)
		{
			is_dead(&info->philo[i]);
			if (info->all_eat_cnt == info->num_philo)
				info->all_eat = 1;
			i++;
		}
		i = 0;
		if (info->philo_die == 1 || info->all_eat == 1)
		{
			while (i < info->num_philo)
			{
				if (info->use_forks[i] == 1)
					pthread_mutex_unlock(&info->forks[i]);
				i++;
			}
			info->end_time = now_time_ms();
			break ;
		}
	}
}
