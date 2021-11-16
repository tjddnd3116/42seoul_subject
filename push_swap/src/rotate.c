/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:04:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/16 13:54:36 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a, t_stack *b)
{
	int		size;
	t_node	*top;
	int		error;

	error = 1;
	top = a->top;
	size = stack_size(a);
	if (size <= 1)
		return ;
	error = push_last(top->data, a);
	if (error == 0)
	{
		malloc_error(a);
		malloc_error(b);
	}
	pop(a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *a, t_stack *b)
{
	int		size;
	t_node	*top;
	int		error;

	error = 1;
	top = b->top;
	size = stack_size(b);
	if (size <= 1)
		return ;
	error = push_last(top->data, b);
	if (error == 0)
	{
		malloc_error(a);
		malloc_error(b);
	}
	pop(b);
	ft_putstr_fd("rb\n", 1);
}

void	retate_all(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
	ft_putstr_fd("rr\n", 1);
}
