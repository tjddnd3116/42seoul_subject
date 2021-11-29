/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:41 by soum              #+#    #+#             */
/*   Updated: 2021/11/29 15:34:03 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_linked_list(t_info *info)
{
	t_stack	*new_a_stack;
	t_stack	*new_b_stack;

	new_a_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_a_stack == NULL)
		exit(0);
	new_b_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_b_stack == NULL)
		exit(0);
	new_a_stack->top = NULL;
	new_b_stack->top = NULL;
	info->a_stack = new_a_stack;
	info->b_stack = new_b_stack;
}

long long	ft_atoi2(const char *str)
{
	int			index;
	int			sign;
	long long	result;

	sign = 1;
	index = 0;
	result = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10;
		result += str[index] - '0';
		index++;
	}
	return (result * sign);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*top;

	top = stack->top;
	size = 0;
	while (top != NULL)
	{
		size++;
		top = top->next;
	}
	return (size);
}

void	init_count(t_info *info)
{
	info->pa_count = 0;
	info->pb_count = 0;
	info->ra_count = 0;
	info->rb_count = 0;
}
