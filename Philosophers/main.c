/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:01:53 by soum              #+#    #+#             */
/*   Updated: 2021/12/09 20:01:06 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (argc == 5 || argc == 6)
	{
		init_info(info, argc, argv);
		create_philo(info);
		main_thread(info);
		//join_thread(info);
		print_all_last_eat(info);
	}
	free(info);
}
