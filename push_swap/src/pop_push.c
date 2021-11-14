/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:23:46 by soum              #+#    #+#             */
/*   Updated: 2021/11/12 21:34:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pop(t_stack *stack)
{
	t_node	*top;

	top = stack->top;
	stack->top = top->next;
	free(top);
	if (stack->top != NULL)
		stack->top->pre = NULL;
}

int	push(int data, t_stack *stack)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	tmp = stack->top;
	if (tmp == NULL)
	{
		stack->top = new_node;
		new_node->data = data;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		tmp->pre = new_node;
		new_node->data = data;
		new_node->next = tmp;
		new_node->pre = NULL;
		stack->top = new_node;
	}
	return (1);
}

int	push_last(int data, t_stack *stack)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	tmp = stack->top;
	if (tmp == NULL)
	{
		stack->top = new_node;
		new_node->data = data;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->pre = tmp;
		new_node->next = NULL;
		new_node->data = data;
	}
	return (1);
}

void	pop_last(t_stack *stack)
{
	t_node	*last;
	t_node	*last_pre;

	last = last_stack(stack);
	last_pre = last->pre;
	free(last);
	last_pre->next = NULL;
}
