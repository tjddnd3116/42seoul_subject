/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:15:18 by soum              #+#    #+#             */
/*   Updated: 2022/01/04 17:25:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo)
{
	long long	now_time;

	now_time = now_time_ms();
	if (now_time - philo->last_eat > philo->info->time_die)
	{
		print_message(philo, "died");
		philo->info->philo_die = 1;
		return (1);
	}
	return (0);
}

void	hold_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
	philo->info->use_forks[philo->l_fork] = 1;
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
	philo->info->use_forks[philo->r_fork] = 1;
	print_message(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	int			time_to_eat;
	long long	start_time;
	long long	end_time;
	long long	diff_time;

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
	pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
	philo->info->use_forks[philo->l_fork] = 0;
	pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
	philo->info->use_forks[philo->r_fork] = 0;
}

void	sleeping(t_philo *philo)
{
	int			time_to_sleep;
	long long	start_time;
	long long	end_time;
	long long	diff_time;

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
}

void	thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
}
