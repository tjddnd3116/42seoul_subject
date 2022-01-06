/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:15:18 by soum              #+#    #+#             */
/*   Updated: 2022/01/06 13:18:03 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	hold_fork(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
	philo->info->use_forks[philo->l_fork] = 1;
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
	philo->info->use_forks[philo->r_fork] = 1;
	print_message(philo, "has taken a fork");
	if (is_dead(philo) == 1)
		return (1);
	return (0);
}

int	eating(t_philo *philo)
{
	int			time_to_eat;
	long long	start_time;
	long long	end_time;
	long long	diff_time;

	if (is_dead(philo) == 1)
		return (1);
	time_to_eat = philo->info->time_eat;
	print_message(philo, "is eating");
	philo->eat_count++;
	start_time = now_time_ms();
	diff_time = 0;
	while (diff_time < time_to_eat)
	{
		end_time = now_time_ms();
		diff_time = end_time - start_time;
		usleep(10);
	}
	philo->last_eat = now_time_ms();
	if (is_dead(philo) == 1)
		return (1);
	return (0);
}

int	put_fork(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
	philo->info->use_forks[philo->l_fork] = 0;
	pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
	philo->info->use_forks[philo->r_fork] = 0;
	if (is_dead(philo) == 1)
		return (1);
	return (0);
}

int	sleeping(t_philo *philo)
{
	int			time_to_sleep;
	long long	start_time;
	long long	end_time;
	long long	diff_time;

	if (is_dead(philo) == 1)
		return (1);
	time_to_sleep = philo->info->time_sleep;
	print_message(philo, "is sleeping");
	start_time = now_time_ms();
	diff_time = 0;
	while (diff_time < time_to_sleep)
	{
		end_time = now_time_ms();
		diff_time = end_time - start_time;
		usleep(10);
	}
	if (is_dead(philo) == 1)
		return (1);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	print_message(philo, "is thinking");
	if (is_dead(philo) == 1)
		return (1);
	return (0);
}
