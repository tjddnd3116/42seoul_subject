/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:24 by soum              #+#    #+#             */
/*   Updated: 2021/11/29 15:48:07 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	{
		info->rrr_flag = 0;
		a_to_b(info, size);
	}
}
