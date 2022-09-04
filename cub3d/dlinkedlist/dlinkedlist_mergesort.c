/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_mergesort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:17 by hseong            #+#    #+#             */
/*   Updated: 2022/08/31 17:24:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "dlinkedlist.h"

#include <stdio.h>

static t_node	*split_list(t_node **head, size_t len, t_comp comp);
static t_node	*join_list(t_node **headptr, t_node *mid, size_t len,
					t_comp comp);
static void		move_node(t_node **sortnode, t_node **node, size_t *count);

void	dlist_mergesort(t_dlist *list, t_comp comp)
{
	t_node	**headptr;
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	headptr = &(list->head);
	if (headptr == NULL || *headptr == NULL || list->size == 1)
		return ;
	list->tail = split_list(headptr, list->size, comp);
	idx = 1;
	node = *headptr;
	node->prev = NULL;
	while (idx < size)
	{
		node->next->prev = node;
		node = node->next;
		++idx;
	}
}

t_node	*split_list(t_node **headptr, size_t len, t_comp comp)
{
	t_node		*mid;
	t_node		*tail;
	size_t		mid_len;
	size_t		idx;

	if (len < 2)
		return (*headptr);
	mid_len = len / 2;
	mid = *headptr;
	idx = 0;
	while (idx < mid_len)
	{
		mid = mid->next;
		++idx;
	}
	tail = split_list(headptr, len / 2, comp);
	tail->next = mid;
	split_list(&(tail->next), (len + 1) / 2, comp);
	return (join_list(headptr, tail->next, len, comp));
}

t_node	*join_list(t_node **headptr, t_node *mid, size_t len, t_comp comp)
{
	t_node	*head;
	t_node	*sortnode;
	size_t	head_count;
	size_t	mid_count;

	head = *headptr;
	head_count = len / 2;
	mid_count = (len + 1) / 2;
	if (comp(head->content, mid->content) < 0)
		move_node(&sortnode, &head, &head_count);
	else
		move_node(&sortnode, &mid, &mid_count);
	*headptr = sortnode;
	while (--len)
	{
		if (head_count > 0 && (mid_count == 0
				|| comp(head->content, mid->content) < 0))
			move_node(&(sortnode->next), &head, &head_count);
		else
			move_node(&(sortnode->next), &mid, &mid_count);
		sortnode = sortnode->next;
	}
	sortnode->next = NULL;
	return (sortnode);
}

void	move_node(t_node **sortnode, t_node **node, size_t *count)
{
	*sortnode = *node;
	(*node) = (*node)->next;
	*count -= 1;
}
