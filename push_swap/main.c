/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:57:18 by soum              #+#    #+#             */
/*   Updated: 2021/11/29 16:05:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	dup_check(t_node *tmp, int num, t_info *info)
{
	while (tmp != NULL)
	{
		if (tmp->data == num)
			error_msg_exit("Error\n", info);
		else
			tmp = tmp->next;
	}
}

int	check_num(char *num_str, t_info *info)
{
	long long	num;
	int			index;
	t_node		*tmp;

	tmp = info->a_stack->top;
	index = 0;
	while (num_str[index] != '\0')
	{
		if (ft_isdigit(num_str[index]) \
				|| (num_str[0] == '+' || num_str[0] == '-'))
			index++;
		else
			error_msg_exit("Error\n", info);
	}
	num = ft_atoi2(num_str);
	if (num < -2147483648 || num > 2147483647)
		error_msg_exit("Error\n", info);
	dup_check(tmp, num, info);
	return ((int)num);
}

void	insert_stack(int num, t_info *info)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		malloc_error(info);
	tmp = info->a_stack->top;
	if (tmp == NULL)
	{
		info->a_stack->top = new_node;
		new_node->data = num;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->pre = tmp;
		new_node->next = NULL;
		new_node->data = num;
	}
}

void	check_and_insert_num_str(char *num_str, t_info *info)
{
	char	**tmp_num_str;
	int		index;
	int		num;

	index = 0;
	tmp_num_str = ft_split(num_str, ' ');
	if (tmp_num_str == NULL)
		malloc_error(info);
	while (tmp_num_str[index] != NULL)
	{
		num = check_num(tmp_num_str[index], info);
		insert_stack(num, info);
		free(tmp_num_str[index]);
		index++;
	}
	free(tmp_num_str);
}

int	main(int argc, char **argv)
{
	int		index;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	index = 0;
	create_linked_list(info);
	if (argc > 1)
	{
		info->write_flag = 1;
		while (++index < argc)
			check_and_insert_num_str(argv[index], info);
		sorting(info);
		free_stack(info);
	}
	else
		free_stack(info);
}
