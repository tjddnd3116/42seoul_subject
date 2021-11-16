/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:24 by soum              #+#    #+#             */
/*   Updated: 2021/11/16 20:53:33 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	test_print(t_stack *a, t_stack *b)
{
	t_node	*a_tmp;
	t_node	*b_tmp;
	int		a_size;
	int		b_size;

	a_tmp = a->top;
	b_tmp = b->top;
	a_size = stack_size(a);
	b_size = stack_size(b);
	while (a_tmp != NULL || b_tmp != NULL)
	{
		if (a_tmp != NULL)
		{
			printf("%d ", a_tmp->data);
			a_tmp = a_tmp->next;
		}
		else if (a_tmp == NULL)
			printf("  ");
		if (b_tmp != NULL)
		{
			printf("%d\n", b_tmp->data);
			b_tmp = b_tmp->next;
		}
		else if (b_tmp == NULL)
			printf("  \n");
	}
	printf("a b\n");
	printf("%d %d\n", a_size, b_size);
	printf("---------------\n");
}

void	is_all_sorted(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		num;
	int		next_num;

	node = a->top;
	num = node->data;
	node = node->next;
	while (node)
	{
		next_num = node->data;
		if (next_num > num)
		{
			num = next_num;
			node = node->next;
		}
		else
			return ;
	}
	free_stack(a);
	free_stack(b);
	exit(0);
}

void	sorting(t_stack *a, t_stack *b)
{
	int	size;

	is_all_sorted(a, b);
	size = stack_size(a);
	if (size == 2)
		size_2_sort(a);
	else if (size == 3)
		size_3_sort(a, b);
	else if (size == 4)
		size_4_sort(a, b);
	else if (size == 5)
		size_5_sort(a, b);
	else
		//quick_sort(a, b);
	test_print(a, b);
}
