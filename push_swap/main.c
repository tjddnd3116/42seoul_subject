/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:57:18 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 20:28:54 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	dup_check(t_node *tmp, int num, t_info *info)
{
	while (tmp != NULL)
	{
		if (tmp->data == num)
		{
			free_stack(info);
			error_msg_exit("Error\n");
		}
		else
			tmp = tmp->next;
	}
}

void	create_linked_list(t_info *info)
{
	t_stack	*new_a_stack;
	t_stack *new_b_stack;

	new_a_stack = (t_stack *)malloc(sizeof(t_stack));
	new_b_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_a_stack == NULL || new_b_stack == NULL)
		exit(0);
	new_a_stack->top = NULL;
	new_b_stack->top = NULL;
	info->a_stack = new_a_stack;
	info->b_stack = new_b_stack;
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
		if ((num_str[index] >= '0' && num_str[index] <= '9') \
				|| (num_str[index] == '+' || num_str[index] == '-'))
			index++;
		else
		{
			free_stack(info);
			error_msg_exit("Error\n");
		}
	}
	num = ft_atoi2(num_str);
	if (num < -2147483648 || num > 2147483647)
	{
		free_stack(info);
		error_msg_exit("Error");
	}
	dup_check(tmp, num, info);
	return ((int)num);
}

void	insert_stack(char *num_str, t_info *info)
{
	int		num;
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		malloc_error(info);
	num = check_num(num_str, info);
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

int	main(int argc, char **argv)
{
	int		index;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));;
	index = 0;
	create_linked_list(info);
	if (argc > 1)
	{
		info->write_flag = 1;
		while (++index < argc)
			insert_stack(argv[index], info);
		sorting(info);
		//test_print(info);
	}
	else
		free_stack(info);
}
