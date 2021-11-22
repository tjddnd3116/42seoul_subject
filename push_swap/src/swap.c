/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:52:12 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 15:06:39 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_info *info)
{
	t_node	*top;
	t_node	*top_next;
	int		tmp_data;
	int		size;

	size = stack_size(info->b_stack);
	top = info->b_stack->top;
	top_next = top->next;
	if (size <= 1)
		return ;
	else
	{
		tmp_data = top->data;
		top->data = top_next->data;
		top_next->data = tmp_data;
	}
	ft_putstr_fd("sb\n", 1);
}

void	swap_a(t_info *info)
{
	t_node	*top;
	t_node	*top_next;
	int		tmp_data;
	int		size;

	size = stack_size(info->a_stack);
	top = info->a_stack->top;
	top_next = top->next;
	if (size <= 1)
		return ;
	else
	{
		tmp_data = top->data;
		top->data = top_next->data;
		top_next->data = tmp_data;
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_all(t_info *info)
{
	swap_a(info);
	swap_b(info);
	ft_putstr_fd("ss\n", 1);
}
