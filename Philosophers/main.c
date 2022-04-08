/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:27:44 by soum              #+#    #+#             */
/*   Updated: 2022/04/07 22:37:31 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		return (0);
	if (argc != 5 && argc != 6)
		return (all_free_exit(info, "Error : argument count"));
	if (!(init_info(info, argc, argv)))
		return (all_free_exit(info, "Error :init"));
	if (!(create_philo(info)))
		return (all_free_exit(info, "Error : thread create"));
	main_thread(info);
	join_thread(info);
	detach_destroy_all(info);
	all_free_exit(info, NULL);
	return (0);
}
