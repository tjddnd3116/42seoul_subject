/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:39:44 by soum              #+#    #+#             */
/*   Updated: 2021/11/25 12:56:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	malloc_error(t_info *info)
{
	free_stack(info);
	exit(0);
}

void	error_msg_exit(char *msg, t_info *info)
{
	ft_putstr_fd(msg, 2);
	free_stack(info);
	exit(0);
}

void	free_stack(t_info *info)
{
	t_node	*a_now;
	t_node	*a_next;
	t_node	*b_now;
	t_node	*b_next;

	a_now = info->a_stack->top;
	b_now = info->b_stack->top;
	while (a_now)
	{
		a_next = a_now->next;
		free(a_now);
		a_now = a_next;
	}
	while (b_now)
	{
		b_next = b_now->next;
		free(b_now);
		b_now = b_next;
	}
	free(info->a_stack);
	free(info->b_stack);
	free(info);
}
