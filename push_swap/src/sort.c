/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:24 by soum              #+#    #+#             */
/*   Updated: 2021/11/13 19:09:55 by soum             ###   ########.fr       */
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

void	sorting(t_stack *a, t_stack *b)
{
	test_print(a, b);
	swap_a(a);
	test_print(a, b);
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	test_print(a, b);
	rotate_a(a, b);
	rotate_b(a, b);
	test_print(a, b);
	reverse_a(a, b);
	reverse_b(a, b);
	test_print(a, b);
	swap_a(a);
	test_print(a, b);
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
	test_print(a, b);
	system("leaks push_swap");
}
