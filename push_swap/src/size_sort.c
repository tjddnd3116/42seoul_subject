/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:18:12 by soum              #+#    #+#             */
/*   Updated: 2021/11/16 16:20:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	size_2_sort(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (tmp->data > tmp->next->data)
		swap_a(stack);
}

void	size_3_sort(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		max_locate;

	tmp = a->top;
	max_locate = find_max_locate(tmp);
	if (max_locate == 0)
		rotate_a(a, b);
	else if (max_locate == 1)
		reverse_a(a, b);
	size_2_sort(a);
}

void	size_4_sort(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		min_locate;

	tmp = a->top;
	min_locate = find_min_locate(tmp);
	if (min_locate <= 2)
	{
		while (min_locate-- != 0)
			rotate_a(a, b);
	}
	else if (min_locate == 3)
		reverse_a(a, b);
	push_b(a, b);
	size_3_sort(a, b);
	push_a(a, b);
}

void	size_5_sort(t_stack *a, t_stack *b)
{
	t_node *tmp;
	int min_locate;

	tmp = a->top;
	min_locate = find_min_locate(tmp);
	if (min_locate <= 2)
	{
		while (min_locate-- != 0)
			rotate_a(a, b);
	}
	else if (min_locate <= 4)
	{
		while (min_locate++ != 5)
			reverse_a(a, b);
	}
	push_b(a, b);
	size_4_sort(a, b);
	push_a(a, b);
}
