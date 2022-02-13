/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:54:17 by soum              #+#    #+#             */
/*   Updated: 2022/02/13 13:25:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "./Libft/libft.h"

int	g_status = 0;

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = (t_data *)malloc(sizeof(t_data));
	init_struct(data, envp);
	while (1)
	{
		show_prompt(data);
		if (check_cmd(data) == 0)
		{
			parsing(data);
			free_cmd_list(data);
		}
	}
	free_env_list(data);
	return (0);
}
