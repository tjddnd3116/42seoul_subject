/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:54:17 by soum              #+#    #+#             */
/*   Updated: 2022/02/02 16:20:35 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "./Libft/libft.h"

void all_print_list(t_data *data)
{
	char *cmd_set;
	t_m_list *list;
	t_cmd *cmd;
	int i;
	int cmd_index;

	i = 0;
	cmd_set = data->cmd_set;
	list = data->lstlast;
	printf("cmd_set : %s\n", cmd_set);
	printf("----------\n");
	printf("list_set\n");
	while (list)
	{
		cmd = list->content;
		printf("%d - list\n", i);
		printf("flag : %d\n", cmd->flag);
		printf("----cmd----\n");
		cmd_index = 0;
		while (cmd->cmdline[cmd_index])
		{
			printf("	%s \n", cmd->cmdline[cmd_index]);
			cmd_index++;
		}
		printf("\n");
		i++;
		list = list->next;
	}

}

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
			//all_print_list(data);
			free_cmd_list(data);
		}
		//free_env_list(data);
		//system("leaks minishell");
	}
	return (0);
}
