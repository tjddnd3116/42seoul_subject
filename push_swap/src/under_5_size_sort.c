/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_5_size_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:18:12 by soum              #+#    #+#             */
/*   Updated: 2021/11/25 12:15:29 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	size_2_sort(t_info *info)
{
	t_node	*tmp;

	tmp = info->a_stack->top;
	if (tmp->data > tmp->next->data)
		swap_a(info);
}

void	size_3_sort(t_info *info)
{
	t_node	*tmp;
	int		max_locate;

	tmp = info->a_stack->top;
	max_locate = find_max_locate(tmp, 3);
	if (max_locate == 0)
		rotate_a(info);
	else if (max_locate == 1)
		reverse_a(info);
	size_2_sort(info);
}

void	size_4_sort(t_info *info)
{
	t_node	*tmp;
	int		min_locate;

	tmp = info->a_stack->top;
	min_locate = find_min_locate(tmp, 4);
	if (min_locate <= 2)
	{
		while (min_locate-- != 0)
			rotate_a(info);
	}
	else if (min_locate == 3)
		reverse_a(info);
	push_b(info);
	size_3_sort(info);
	push_a(info);
}

void	size_5_sort(t_info *info)
{
	t_node	*tmp;
	int		min_locate;

	tmp = info->a_stack->top;
	min_locate = find_min_locate(tmp, 5);
	if (min_locate <= 2)
	{
		while (min_locate-- != 0)
			rotate_a(info);
	}
	else if (min_locate <= 4)
	{
		while (min_locate++ != 5)
			reverse_a(info);
	}
	push_b(info);
	size_4_sort(info);
	push_a(info);
}
