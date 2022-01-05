/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:28:23 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 17:05:25 by soum             ###   ########.fr       */
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
