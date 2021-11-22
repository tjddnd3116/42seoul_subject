/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:59:07 by soum              #+#    #+#             */
/*   Updated: 2021/11/22 19:16:33 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_num(t_node *node, int size)
{
	t_node	*tmp;
	int		min_num;
	int		index ;

	index = 0;
	tmp = node;
	min_num = tmp->data;
	while (index++ < size)
	{
		if (tmp->data < min_num)
			min_num = tmp->data;
		tmp = tmp->next;
	}
	return (min_num);
}

int	find_max_num(t_node *node, int size)
{
	t_node	*tmp;
	int		max_num;
	int		index;

	index = 0;
	tmp = node;
	max_num = tmp->data;
	while (index++ < size)
	{
		if (tmp->data > max_num)
			max_num = tmp->data;
		tmp = tmp->next;
	}
	return (max_num);
}

int	find_min_locate(t_node *node, int size)
{
	int		min_num;
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	min_num = find_min_num(node, size);
	while (index < size)
	{
		if (min_num == tmp->data)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	find_max_locate(t_node *node, int size)
{
	int		max_num;
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	max_num = find_max_num(node, size);
	while (index < size)
	{
		if (max_num == tmp->data)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}
