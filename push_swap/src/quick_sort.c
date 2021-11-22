/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:26:55 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 20:18:49 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//#include <stdio.h>

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

void	under_3_sort(t_info *info, int size, char stack)
{
	int i;

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
}

void	a_to_b(t_info *info, int size)
{
	int	b_pivot;
	int	s_pivot;
	int	index;
	int ra;
	int rb;
	int pb;

	ra = 0;
	rb = 0;
	pb = 0;
	index = 0;
	init_count(info);
	b_pivot = big_pivot(info->a_stack, size);
	s_pivot = small_pivot(info->a_stack, size);
	//printf("******a->b (%d)*****\n", size);
	//test_print(info);
	//printf("b_pivot : %d, s_pivot : %d\n", b_pivot, s_pivot);
	if (size <= 3)
	{
		under_3_sort(info, size, 'a');
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
	//printf("ra : %d, rb : %d, pb-rb : %d\n", info->ra_count, info->rb_count, info->pb_count - info->rb_count);
	ra = info->ra_count;
	rb = info->rb_count;
	pb = info->pb_count;
	rrr(info, ra, rb);
	a_to_b(info, ra);
	b_to_a(info, rb);
	b_to_a(info, pb - rb);
}

void	b_to_a(t_info *info, int size)
{
	int	b_pivot;
	int	s_pivot;
	int	index;
	int pa;
	int ra;
	int rb;

	index = 0;
	init_count(info);
	b_pivot = big_pivot(info->b_stack, size);
	s_pivot = small_pivot(info->b_stack ,size);
	//printf("******b->a(%d)*******\n", size);
	//test_print(info);
	//printf("b_pivot : %d, s_pivot : %d\n", b_pivot, s_pivot);
	if (size <= 3)
	{
		under_3_sort(info, size, 'b');
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
	//printf("pa-ra : %d, ra : %d, rb : %d\n", info->pa_count - info->ra_count, info->ra_count, info->rb_count);
	pa = info->pa_count;
	ra = info->ra_count;
	rb = info->rb_count;
	a_to_b(info, pa - ra);
	rrr(info, ra, rb);
	a_to_b(info, ra);
	b_to_a(info, rb);

}

void	over_5_sort(t_info *info)
{
	int size;

	size = stack_size(info->a_stack);
	a_to_b(info, size);
}
