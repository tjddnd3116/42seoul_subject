/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:40:33 by soum              #+#    #+#             */
/*   Updated: 2021/11/12 21:44:51 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*last_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*top;

	top = stack->top;
	while (top->next != NULL)
		top = top->next;
	last = top;
	return (last);
}

void	reverse_a(t_stack *a, t_stack *b)
{
	int		size;
	int		error;
	t_node	*last;
	t_node	*top;

	error = 1;
	top = a->top;
	last = last_stack(a);
	size = stack_size(a);
	if (size <= 1)
		return ;
	error = push(last->data, a);
	if (error == 0)
	{
		malloc_error(a);
		malloc_error(b);
	}
	pop_last(a);
}

void	reverse_b(t_stack *a, t_stack *b)
{
	int		size;
	int		error;
	t_node	*last;
	t_node	*top;

	error = 1;
	top = b->top;
	last = last_stack(b);
	size = stack_size(b);
	if (size <= 1)
		return ;
	error = push(last->data, b);
	if (error == 0)
	{
		malloc_error(a);
		malloc_error(b);
	}
	pop_last(b);
}

void	reverse_all(t_stack *a, t_stack *b)
{
	reverse_a(a, b);
	reverse_b(a, b);
}
