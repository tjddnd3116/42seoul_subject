/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:27 by soum              #+#    #+#             */
/*   Updated: 2021/11/24 14:16:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_count(t_info *info)
{
	info->pa_count = 0;
	info->pb_count = 0;
	info->ra_count = 0;
	info->rb_count = 0;
}

void	sort_arr(long *arr, t_stack *stack, int size)
{
	long	tmp;
	t_node	*tmp_node;
	int		index;

	index = 0;
	tmp_node = stack->top;
	while (index < size -1)
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

int	big_pivot(t_stack *stack, int size)
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
	pivot = arr[size / 4 * 3];
	free(arr);
	return (pivot);
}

int	small_pivot(t_stack *stack, int size)
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
	pivot = arr[size / 4];
	free(arr);
	return (pivot);
}
