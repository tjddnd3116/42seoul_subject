/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:18:12 by soum              #+#    #+#             */
/*   Updated: 2021/11/15 20:23:35 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
void	size_2_sort(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->top;
	if (tmp->data > tmp->next->data)
		swap_a(stack);
}

void	size_3_sort(t_stack *stack)
{
	t_node	*tmp;
	int		max_locate;

	tmp = stack->top;
	max_locate = find_max_num(tmp);
	printf(" max locate : %d\n", max_locate);
}
/*
void	size_4_sort(t_stack *a, t_stack *b)
{
}

void	size_5_sort(t_stack *a, t_stack *b)
{

}
*/
