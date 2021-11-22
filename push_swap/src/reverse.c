/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:40:33 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 17:25:36 by soum             ###   ########.fr       */
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

void	reverse_a(t_info *info)
{
	int		size;
	int		error;
	t_node	*last;
	t_node	*top;

	error = 1;
	top = info->a_stack->top;
	last = last_stack(info->a_stack);
	size = stack_size(info->a_stack);
	if (size <= 1)
		return ;
	error = push(last->data, info->a_stack);
	if (error == 0)
		malloc_error(info);
	pop_last(info->a_stack);
	if (info->write_flag)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_b(t_info *info)
{
	int		size;
	int		error;
	t_node	*last;
	t_node	*top;

	error = 1;
	top = info->b_stack->top;
	last = last_stack(info->b_stack);
	size = stack_size(info->b_stack);
	if (size <= 1)
		return ;
	error = push(last->data, info->b_stack);
	if (error == 0)
		malloc_error(info);
	pop_last(info->b_stack);
	if (info->write_flag)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_all(t_info *info)
{
	reverse_a(info);
	reverse_b(info);
	ft_putstr_fd("rrr\n", 1);
}
