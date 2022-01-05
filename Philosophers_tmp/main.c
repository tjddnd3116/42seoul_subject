/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:27:44 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 19:53:00 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		return (0);
	printf("here");
	if (argc != 5 && argc != 6)
		return (all_free_exit(info, "Error : argument count"));
	printf("here");
	if (!(init_info(info, argc, argv)))
		return (all_free_exit(info, "Error :init"));
	if (!(create_philo(info)))
		return (all_free_exit(info, "Error : thread create"));
	printf("here\n");
	main_thread(info);
	join_thread(info);
	all_free_exit(info, NULL);
	return (0);
}
