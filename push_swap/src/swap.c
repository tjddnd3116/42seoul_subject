/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:52:12 by soum              #+#    #+#             */
/*   Updated: 2021/11/12 21:45:44 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stack *b)
{
	t_node	*top;
	t_node	*top_next;
	int		tmp_data;
	int		size;

	size = stack_size(b);
	top = b->top;
	top_next = top->next;
	if (size <= 1)
		return ;
	else
	{
		tmp_data = top->data;
		top->data = top_next->data;
		top_next->data = tmp_data;
	}
}

void	swap_a(t_stack *a)
{
	t_node	*top;
	t_node	*top_next;
	int		tmp_data;
	int		size;

	size = stack_size(a);
	top = a->top;
	top_next = top->next;
	if (size <= 1)
		return ;
	else
	{
		tmp_data = top->data;
		top->data = top_next->data;
		top_next->data = tmp_data;
	}
}

void	swap_all(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}
