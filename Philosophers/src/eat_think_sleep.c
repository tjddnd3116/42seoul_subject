/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:36:11 by soum              #+#    #+#             */
/*   Updated: 2021/12/04 20:15:49 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	int			time_to_eat;
	int			time_to_die;
	long long	now_time;

	time_to_die = philo->info->time_die;
	time_to_eat = philo->info->time_eat;
	now_time = now_time_ms();
	if (now_time - philo->last_eat > time_to_die)
	{
		print_message(philo, "died");
		philo->info->philo_die = 1 ;
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
		print_message(philo, "has taken a fork");
		print_message(philo, "is eating");
		philo->eat_count++;
		usleep(time_to_eat * 1000);
		philo->last_eat =now_time_ms();
		pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
	}
}

void	sleeping(t_philo *philo)
{
	int			time_to_sleep;

	time_to_sleep = philo->info->time_sleep;
	usleep(time_to_sleep * 1000);
	print_message(philo, "is sleeping");
}


void	thinking(t_philo *philo)
{
	long long	now_time;

	now_time = now_time_ms();
	print_message(philo, "is thinking");
}

