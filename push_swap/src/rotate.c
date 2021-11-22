/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:04:51 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 20:17:05 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_info *info)
{
	int		size;
	t_node	*top;
	int		error;
	
	info->ra_count++;
	error = 1;
	top = info->a_stack->top;
	size = stack_size(info->a_stack);
	if (size <= 1)
		return ;
	error = push_last(top->data, info->a_stack);
	if (error == 0)
		malloc_error(info);
	pop(info->a_stack);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_info *info)
{
	int		size;
	t_node	*top;
	int		error;
	
	info->rb_count++;
	error = 1;
	top = info->b_stack->top;
	size = stack_size(info->b_stack);
	if (size <= 1)
		return ;
	error = push_last(top->data, info->b_stack);
	if (error == 0)
		malloc_error(info);
	pop(info->b_stack);
	ft_putstr_fd("rb\n", 1);
}

void	retate_all(t_info *info)
{
	rotate_a(info);
	rotate_b(info);
	ft_putstr_fd("rr\n", 1);
}
