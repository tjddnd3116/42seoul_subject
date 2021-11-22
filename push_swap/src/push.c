/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:26:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 18:22:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_info *info)
{
	t_node	*b_top;
	int		error;

	error = 1;
	b_top = info->b_stack->top;
	if (b_top == NULL)
		return ;
	error = push(b_top->data, info->a_stack);
	if (error == 0)
		malloc_error(info);
	pop(info->b_stack);
	info->pa_count++;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_info *info)
{
	t_node	*a_top;
	int		error;

	error = 1;
	a_top = info->a_stack->top;
	if (a_top == NULL)
		return ;
	error = push(a_top->data, info->b_stack);
	if (error == 0)
		malloc_error(info);
	pop(info->a_stack);
	info->pb_count++;
	ft_putstr_fd("pb\n", 1);
}
