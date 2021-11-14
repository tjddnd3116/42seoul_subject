/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:41 by soum              #+#    #+#             */
/*   Updated: 2021/11/12 20:39:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
