/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:28:23 by soum              #+#    #+#             */
/*   Updated: 2022/01/06 13:35:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	all_free_exit(t_info *info, char *str)
{
	if (info->philo != NULL)
		free(info->philo);
	if (info->forks != NULL)
		free(info->forks);
	if (info->use_forks != NULL)
		free(info->use_forks);
	if (info != NULL)
		free(info);
	if (str != NULL)
		printf("%s", str);
	return (0);
}

void	detach_destroy_all(t_info *info)
{
	int	num_philo;
	int	index;

	num_philo = info->num_philo;
	index = 0;
	while (index < num_philo)
	{
		pthread_detach(info->philo[index].thread);
		pthread_mutex_destroy(&info->forks[index]);
		index++;
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->all_eat_m);
}
