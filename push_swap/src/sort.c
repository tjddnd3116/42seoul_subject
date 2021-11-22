/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:24 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 19:22:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	test_print(t_info *info)
{
	t_node	*a_tmp;
	t_node	*b_tmp;
	int		a_size;
	int		b_size;

	a_tmp = info->a_stack->top;
	b_tmp = info->b_stack->top;
	a_size = stack_size(info->a_stack);
	b_size = stack_size(info->b_stack);
	printf("-----------------\n");
	while (a_tmp != NULL || b_tmp != NULL)
	{
		if (a_tmp != NULL)
		{
			printf("%d ", a_tmp->data);
			a_tmp = a_tmp->next;
		}
		else if (a_tmp == NULL)
			printf("  ");
		if (b_tmp != NULL)
		{
			printf("%d\n", b_tmp->data);
			b_tmp = b_tmp->next;
		}
		else if (b_tmp == NULL)
			printf("  \n");
	}
	printf("a b\n");
	printf("%d %d\n", a_size, b_size);
	printf("---------------\n");
}

void	is_all_sorted(t_info *info)
{
	t_node	*node;
	int		num;
	int		next_num;

	node = info->a_stack->top;
	num = node->data;
	node = node->next;
	while (node)
	{
		next_num = node->data;
		if (next_num > num)
		{
			num = next_num;
			node = node->next;
		}
		else
			return ;
	}
	free_stack(info);
	exit(0);
}

void	sorting(t_info *info)
{
	int	size;

	is_all_sorted(info);
	size = stack_size(info->a_stack);
	if (size == 2)
		size_2_sort(info);
	else if (size == 3)
		size_3_sort(info);
	else if (size == 4)
		size_4_sort(info);
	else if (size == 5)
		size_5_sort(info);
	else
		over_5_sort(info);
	//test_print(info);
}
