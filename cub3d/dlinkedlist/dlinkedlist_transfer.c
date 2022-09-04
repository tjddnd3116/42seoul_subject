/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_transfer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:07:35 by hseong            #+#    #+#             */
/*   Updated: 2022/06/11 04:07:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlinkedlist.h"

void	array_to_dlist(t_dlist *list, const void *arr,
			size_t size, size_t count)
{
	void	*unit;
	size_t	idx;

	if (arr == NULL || size == 0)
		return ;
	idx = 0;
	while (idx < count)
	{
		unit = malloc(size);
		ft_memcpy(unit, arr + size * idx, size);
		push_back(list, unit);
		++idx;
	}
}

t_dlist	*array_to_dlist_init(const void *arr, size_t size, size_t count)
{
	t_dlist	*new_list;

	new_list = dlist_init();
	array_to_dlist(new_list, arr, size, count);
	return (new_list);
}

void	*dlist_to_array(t_dlist *list, void *(*extract_content)(void *))
{
	void	**array;
	t_node	*node;
	size_t	idx;
	size_t	size;

	array = malloc(sizeof(void *) * (list->size + 1));
	idx = 0;
	size = list->size;
	node = list->head;
	array[size] = NULL;
	while (idx < size)
	{
		array[idx] = extract_content(node->content);
		node = node->next;
		++idx;
	}
	return (array);
}
