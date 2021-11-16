/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:59:07 by soum              #+#    #+#             */
/*   Updated: 2021/11/15 20:25:30 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_num(t_node *node)
{
	int		index;
	int		locate;
	int		max;
	t_node	*tmp;

	tmp = node;
	locate = 0;
	index = 0;
	max = tmp->data;
	tmp = tmp->next;
	while (index < 2)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			locate++;
		}
		tmp = tmp->next;
		index++;
	}
	return (locate);
}
