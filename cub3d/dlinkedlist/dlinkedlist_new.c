/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/08/31 15:18:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlinkedlist.h"

int	push_front(t_dlist *list, void *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	if (list->head == NULL)
		list->tail = new_node;
	else
		list->head->prev = new_node;
	new_node->content = content;
	new_node->next = list->head;
	new_node->prev = NULL;
	list->head = new_node;
	++list->size;
	return (1);
}

int	push_back(t_dlist *list, void *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	if (list->tail == NULL)
		list->head = new_node;
	else
		list->tail->next = new_node;
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = list->tail;
	list->tail = new_node;
	++list->size;
	return (1);
}

int	insert_at(t_dlist *list, t_node *at, void *content)
{
	t_node	*trav;
	t_node	*new_node;

	trav = list->head;
	while (trav && trav != at)
		trav = trav->next;
	if (trav == NULL || trav != at)
		return (0);
	new_node = malloc(sizeof(t_node));
	new_node->content = content;
	++list->size;
	if (at == list->head)
	{
		new_node->prev = NULL;
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
		return (1);
	}
	trav = trav->prev;
	trav->next = new_node;
	new_node->prev = trav;
	new_node->next = at;
	at->prev = new_node;
	return (1);
}
