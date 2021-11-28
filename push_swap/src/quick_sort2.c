/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:53:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/28 19:51:07 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	size_4_sort2(t_info *info)
{
	t_node *tmp;
	int		max_locate;

	tmp = info->a_stack->top;
	max_locate = find_max_locate(tmp, 4);
	if (max_locate == 3)
		size_3_sort2(info);
	else if (max_locate == 2)
	{
		push_b(info);
		size_3_sort2(info);
		push_a(info);
		size_3_sort2(info);
	}
	else if (max_locate == 1)
	{
		push_b(info);
		size_3_sort2(info);
		push_a(info);
		size_3_sort2(info);
	}
	else if (max_locate == 0)
	{
		size_3_sort2(info);
		push_b(info);
		size_3_sort2(info);
		push_a(info);
		size_3_sort2(info);
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
		while (rb)
		{
			reverse_b(info);
			rb--;
		}
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
			else if (ra)
			{
				reverse_a(info);
				ra--;
			}
			else if (rb)
			{
				reverse_b(info);
				rb--;
			}
		}	
	}
}
