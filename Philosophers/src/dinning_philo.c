/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:26:00 by soum              #+#    #+#             */
/*   Updated: 2021/12/03 20:14:13 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>
void	*eat_think_sleep(void *v_philo)
{
	t_philo *philo= (t_philo *)v_philo;
	
	eating(philo);
	//thinking(philo);
	//sleeping(philo);
	//eat_think_sleep(v_philo);
	return (0);
}

void	create_philo(t_info *info)
{
	int	thr_id;
	int num_of_philo;
	int index;

	index = 0;
	num_of_philo = info->num_philo;
	while (index < num_of_philo)
	{
		info->philo[index].info = info;
		info->philo[index].id = index + 1;
		info->philo[index].l_fork = index + 1;
		info->philo[index].r_fork = index + 2;
		if (index == num_of_philo - 1)
			info->philo[index].r_fork = 1;
		thr_id = pthread_create(&info->philo[index].thread, NULL, eat_think_sleep, (void *)&info->philo[index]);
		if (thr_id < 0)
			error();
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
}

void	join_thread(t_info *info)
{
	int num_philo;
	int index;

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
	init_mutex(info);
	create_philo(info);
	join_thread(info);
}
