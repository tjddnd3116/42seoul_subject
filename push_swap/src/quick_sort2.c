/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:53:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 21:06:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_info *info, int ra, int rb)
{
	//int	ra;
	//int	rb;

	//ra = info->ra_count;
	//rb = info->rb_count;
	while (ra || rb)
	{
		//info->write_flag = 1;
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
