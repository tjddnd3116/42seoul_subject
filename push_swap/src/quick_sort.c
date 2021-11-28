/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:26:55 by soum              #+#    #+#             */
/*   Updated: 2021/11/28 19:53:41 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	size_3_sort2(t_info *info)
{
	t_node	*tmp;
	int		max_locate;

	tmp = info->a_stack->top;
	max_locate = find_max_locate(tmp, 3);
	if (max_locate == 2)
	{
		size_2_sort(info);
	}
	else if (max_locate == 1)
	{
		rotate_a(info);
		size_2_sort(info);
		reverse_a(info);
		size_2_sort(info);
	}
	else if (max_locate == 0)
	{
		size_2_sort(info);
		rotate_a(info);
		size_2_sort(info);
		reverse_a(info);
		size_2_sort(info);
	}
}

void	under_4_sort(t_info *info, int size, char stack)
{
	int	i;

	i = 0;
	if (stack == 'b')
	{
		while (i < size)
		{
			push_a(info);
			i++;
		}
	}
	if (size == 1)
		return ;
	else if (size == 2)
		size_2_sort(info);
	else if (size == 3)
		size_3_sort2(info);
	//else if (size == 4)
	//	size_4_sort2(info);
}

void	a_to_b(t_info *info, int size)
{
	int	b_pivot;
	int	s_pivot;
	int	index;

	index = 0;
	init_count(info);
	b_pivot = big_pivot(info->a_stack, size);
	s_pivot = small_pivot(info->a_stack, size);
	if (size <= 3)
	{
		under_4_sort(info, size, 'a');
		return ;
	}
	while (index++ < size)
	{
		if (info->a_stack->top->data >= b_pivot)
			rotate_a(info);
		else
		{
			push_b(info);
			if (info->b_stack->top->data >= s_pivot)
				rotate_b(info);
		}
	}
	recursive(info, 0);
}

void	b_to_a(t_info *info, int size)
{
	int	b_pivot;
	int	s_pivot;
	int	index;

	index = 0;
	init_count(info);
	b_pivot = big_pivot(info->b_stack, size);
	s_pivot = small_pivot(info->b_stack, size);
	if (size <= 3)
	{
		under_4_sort(info, size, 'b');
		return ;
	}
	while (index++ < size)
	{
		if (info->b_stack->top->data < s_pivot)
			rotate_b(info);
		else
		{
			push_a(info);
			if (info->a_stack->top->data < b_pivot)
				rotate_a(info);
		}
	}
	info->rrr_flag = 1;
	recursive(info, 1);
}

void	over_5_sort(t_info *info)
{
	int	size;

	info->rrr_flag = 0;
	size = stack_size(info->a_stack);
	a_to_b(info, size);
}
