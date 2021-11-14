/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:27:48 by soum              #+#    #+#             */
/*   Updated: 2021/11/01 16:20:03 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_window	window;
	int			check_map_error;

	check_map_error = 1;
	if (argc == 2)
	{
		check_map_error = check_ber(&window, argv[1]);
		if (check_map_error == 0)
			error_msg_exit("check .ber!!");
		load_map(argv[1], &window);
		create_window(&window);
		render_image(&window);
		rendering(&window);
		mlx_loop(window.mlx);
	}
	else
		error_msg_exit("./so_long [.ber] !!!");
	return (0);
}
