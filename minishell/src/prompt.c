/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:10:06 by soum              #+#    #+#             */
/*   Updated: 2022/02/12 22:08:47 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	show_prompt(t_data *data)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	data->cmd_set = readline("minishell$ ");
	if (!data->cmd_set)
	{
		printf("\033[1A");
		printf("\033[10C");
		printf(" exit\n");
		free_cmd_list(data);
		free_env_list(data);
		exit(g_status);
	}
	else if (data->cmd_set[0] == '\0')
	{
		free(data->cmd_set);
		data->cmd_set = NULL;
	}
	else
		add_history(data->cmd_set);
}
