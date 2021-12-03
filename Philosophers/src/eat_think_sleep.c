/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:36:11 by soum              #+#    #+#             */
/*   Updated: 2021/12/03 19:48:28 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>
void	eating(t_philo *philo)
{
	int	time_to_eat;

	time_to_eat = philo->info->time_eat;
	printf("i'm %d philo my l_fork : %d, my r_fork : %d\n", philo->id, philo->l_fork , philo->r_fork);
}
/*
void	thinking(t_philo *philo)
{


}

void	sleeping(t_philo *philo)
{


}
*/
