/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:26:00 by soum              #+#    #+#             */
/*   Updated: 2021/12/04 19:42:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*eat_think_sleep(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	while (!philo->info->philo_die)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

void	create_philo(t_info *info)
{
	int	thr_id;
	int	num_of_philo;
	int	index;

	index = 0;
	num_of_philo = info->num_philo;
	while (index < num_of_philo)
	{
		info->philo[index].last_eat = now_time_ms();
		thr_id = pthread_create(&info->philo[index].thread, \
				NULL, eat_think_sleep, (void *)&info->philo[index]);
		if (thr_id < 0)
			error();
		index++;
	}
}

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

void	dinning_philo(t_info *info)
{
	create_philo(info);
	join_thread(info);
}
