/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:39:44 by soum              #+#    #+#             */
/*   Updated: 2021/11/12 20:00:08 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	malloc_error(t_stack *a)
{
	free_stack(a);
	exit(0);
}

void	error_msg_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

void	free_stack(t_stack *a)
{
	t_node	*now;
	t_node	*next;

	now = a->top;
	while (now)
	{
		next = now->next;
		free(now);
		now = next;
	}
	free(a);
}
