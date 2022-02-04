/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:11:04 by soum              #+#    #+#             */
/*   Updated: 2022/02/04 20:16:01 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	init_struct(t_data *data, char **envp)
{
	data->lstlast = NULL;
	data->env = init_env(envp);
	setting_signal();
}

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("minishell$ \n");
		if (rl_on_new_line() == -1) // move to new(empty) line
			exit(1);
		rl_replace_line("", 1); // 문자 입력 후 ctrl+c 눌렀을 때 버퍼 비워줌
		rl_redisplay(); // readline redisplay
	}
}

void	setting_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
