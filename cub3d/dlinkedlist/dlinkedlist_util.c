/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:20:14 by hseong            #+#    #+#             */
/*   Updated: 2022/08/07 13:21:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dlinkedlist.h"

t_dlist	*dlist_init(void)
{
	t_dlist	*new_list;

	new_list = malloc(sizeof(t_dlist));
	*new_list = (t_dlist){NULL, NULL, NULL, 0, 0, 0};
	return (new_list);
}

void	dlist_local_init(t_dlist *list)
{
	*list = (t_dlist){NULL, NULL, NULL, 0, 0, 0};
}

t_node	*dlist_find_content(t_dlist *list, const void *content, size_t size,
	void *(*extract_content)(void *))
{
	t_node	*node;

	node = list->head;
	while (node != NULL)
	{
		if (ft_memcmp(extract_content(node->content), content, size) == 0)
			break ;
		node = node->next;
	}
	return (node);
}

void	dlist_print_forward(t_dlist *list, void (*print_content)(void *))
{
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	node = list->head;
	idx = 0;
	while (idx < size)
	{
		print_content(node->content);
		node = node->next;
		++idx;
	}
}

void	dlist_print_backward(t_dlist *list, void (*print_content)(void *))
{
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	node = list->tail;
	idx = size;
	while (idx > 0)
	{
		print_content(node->content);
		node = node->prev;
		--idx;
	}
}
