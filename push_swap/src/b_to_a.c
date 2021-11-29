/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:53:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/29 15:58:02 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_to_a(t_info *info, int size)
{
	int	b_pivot;
	int	s_pivot;

	init_count(info);
	b_pivot = find_big_pivot(info->b_stack, size);
	s_pivot = find_small_pivot(info->b_stack, size);
	if (size <= 3)
	{
		under_3_sort(info, size, 'b');
		return ;
	}
	while (size--)
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

void	size_2_sort_b_to_a(t_info *info)
{
	t_node	*tmp;

	tmp = info->b_stack->top;
	if (tmp->data < tmp->next->data)
	{
		swap_b(info);
		push_a(info);
		push_a(info);
	}
	else
	{
		push_a(info);
		push_a(info);
	}
}

void	size_3_sort_b_to_a(t_info *info)
{
	t_node	*tmp;
	int		max_locate;

	tmp = info->b_stack->top;
	max_locate = find_max_locate(tmp, 3);
	if (max_locate == 0)
	{
		push_a(info);
		size_2_sort_b_to_a(info);
	}
	else if (max_locate == 1)
	{
		swap_b(info);
		push_a(info);
		size_2_sort_b_to_a(info);
	}
	else if (max_locate == 2)
	{
		push_a(info);
		swap_b(info);
		push_a(info);
		swap_a(info);
		push_a(info);
		size_2_sort(info);
	}
}

void	recursive(t_info *info, int flag)
{
	int	ra;
	int	rb;
	int	pb;
	int	pa;

	ra = info->ra_count;
	rb = info->rb_count;
	pb = info->pb_count;
	pa = info->pa_count;
	if (flag == 0)
	{
		rrr(info, ra, rb);
		a_to_b(info, ra);
		b_to_a(info, rb);
		b_to_a(info, pb - rb);
	}
	else
	{
		a_to_b(info, pa - ra);
		rrr(info, ra, rb);
		a_to_b(info, ra);
		b_to_a(info, rb);
	}
}

void	rrr(t_info *info, int ra, int rb)
{
	if (info->rrr_flag == 0)
	{
		while (rb--)
			reverse_b(info);
	}
	else
	{
		while (ra || rb)
		{
			if (ra && rb)
			{
				info->write_flag = 0;
				reverse_all(info);
				info->write_flag = 1;
				ra--;
				rb--;
			}
			else if (ra--)
				reverse_a(info);
			else if (rb--)
				reverse_b(info);
		}	
	}
}
