/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:26:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/12 21:44:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	t_node	*b_top;
	int		error;

	error = 1;
	b_top = b->top;
	if (b_top == NULL)
		return ;
	error = push(b_top->data, a);
	if (error == 0)
	{
		malloc_error(a);
		malloc_error(b);
	}
	pop(b);
}

void	push_b(t_stack *a, t_stack *b)
{
	t_node	*a_top;
	int		error;

	error = 1;
	a_top = a->top;
	if (a_top == NULL)
		return ;
	error = push(a_top->data, b);
	if (error == 0)
	{
		malloc_error(a);
		malloc_error(b);
	}
	pop(a);
}
