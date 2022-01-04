/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:27:44 by soum              #+#    #+#             */
/*   Updated: 2022/01/04 16:30:27 by soum             ###   ########.fr       */
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
		join_thread(info);
	}
	free(info);
}
