/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:44:18 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 19:51:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_other_philo(t_philo *philo)
{
	while (1)
	{
		usleep(10);
		if (philo->info->philo_idx == philo->info->num_philo - 1)
			break ;
	}
}

int	is_full(t_philo *philo)
{
	int	num_eat;
	int	eat_cnt;

	num_eat = philo->info->num_eat;
	eat_cnt = philo->eat_count;
	if (eat_cnt == num_eat)
	{
		pthread_mutex_lock(&philo->info->all_eat_m);
		philo->info->all_eat_cnt++;
		pthread_mutex_unlock(&philo->info->all_eat_m);
		return (1);
	}
	return (0);
}

void	*eat_think_sleep(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	wait_other_philo(philo);
	if (philo->id % 2 == 1)
		usleep(10000);
	while (!philo->info->philo_die)
	{
		is_dead(philo);
		hold_fork(philo);
		is_dead(philo);
		eating(philo);
		if (is_full(philo) == 1)
			return (0);
		is_dead(philo);
		sleeping(philo);
		is_dead(philo);
		thinking(philo);
	}
	return (0);
}

int	create_philo(t_info *info)
{
	int	thr_id;
	int	num_of_philo;
	int	index;

	index = 0;
	num_of_philo = info->num_philo;
	info->start_time = now_time_ms();
	while (index < num_of_philo)
	{
		info->philo_idx = index;
		info->philo[index].last_eat = now_time_ms();
		thr_id = pthread_create(&info->philo[index].thread, \
				NULL, eat_think_sleep, (void *)&info->philo[index]);
		if (thr_id < 0)
			return (0);
		index++;
	}
	return (1);
}
