/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:27 by soum              #+#    #+#             */
/*   Updated: 2021/11/29 16:24:11 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_arr(long *arr, t_stack *stack, int size)
{
	long	tmp;
	t_node	*tmp_node;
	int		index;

	index = 0;
	tmp_node = stack->top;
	while (index < size - 1)
	{
		if (arr[index] <= arr[index + 1])
			index++;
		else
		{
			tmp = arr[index];
			arr[index] = arr[index + 1];
			arr[index + 1] = tmp;
			index = 0;
		}
	}
}

int	find_big_pivot(t_stack *stack, int size)
{
	long	*arr;
	t_node	*tmp_node;
	int		pivot;
	int		index;

	index = 0;
	tmp_node = stack->top;
	arr = (long *)malloc(sizeof(long) * size + 1);
	while (index < size)
	{
		arr[index] = tmp_node->data;
		index++;
		tmp_node = tmp_node->next;
	}
	arr[index] = '\0';
	sort_arr(arr, stack, size);
	pivot = arr[size / 3 * 2];
	free(arr);
	return (pivot);
}

int	find_small_pivot(t_stack *stack, int size)
{
	long	*arr;
	t_node	*tmp_node;
	int		pivot;
	int		index;

	index = 0;
	tmp_node = stack->top;
	arr = (long *)malloc(sizeof(long) * size + 1);
	while (index < size)
	{
		arr[index] = tmp_node->data;
		index++;
		tmp_node = tmp_node->next;
	}
	arr[index] = '\0';
	sort_arr(arr, stack, size);
	pivot = arr[size / 3];
	free(arr);
	return (pivot);
}
