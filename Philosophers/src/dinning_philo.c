/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:26:00 by soum              #+#    #+#             */
/*   Updated: 2021/12/10 17:33:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_other_philo(t_philo *philo)
{
	while (1)
	{
		if (philo->info->philo_idx == philo->info->num_philo - 1)
		{
			philo->last_eat = philo->info->start_time;
			usleep(100);
			break ;
		}
	}
}

void	*eat_think_sleep(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	pthread_mutex_lock(&philo->info->time_m);
	philo->info->start_time = now_time_ms();
	pthread_mutex_unlock(&philo->info->time_m);
	wait_other_philo(philo);
	if (philo->id % 2 == 1)
	{
		usleep(10000);	
		//usleep(200 * (philo->info->num_philo - philo->id + 1));
	}
	while (!philo->info->philo_die)
	{
		hold_fork(philo);
		eating(philo);
		put_fork(philo);
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
		info->philo_idx = index;
		//info->philo[index].last_eat = now_time_ms();
		thr_id = pthread_create(&info->philo[index].thread, \
				NULL, eat_think_sleep, (void *)&info->philo[index]);
		usleep(500);
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

void	main_thread(t_info *info)
{
	int i;

	i = 0;
	while (1)
	{
		if (info->philo_idx == info->num_philo - 1)
		{
			i = 0;
			while (i < info->num_philo)
			{
				is_dead(&info->philo[i]);
				i++;
			}
			if (info->philo_die == 1)
				break ;
		}
		else
			usleep(100);
	}
}
