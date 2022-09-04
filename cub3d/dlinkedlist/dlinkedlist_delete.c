/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:58:50 by hseong            #+#    #+#             */
/*   Updated: 2022/07/11 20:50:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dlinkedlist.h"

void	dlist_delete(t_dlist *list, void (*delete_content)(void *))
{
	if (list == NULL)
		return ;
	dlist_empty(list, delete_content);
	free(list);
}

void	dlist_empty(t_dlist *list, void (*delete_content)(void *))
{
	size_t		size;
	t_node		*trav_node;

	size = list->size;
	if (size == 0)
		return ;
	trav_node = list->head->next;
	while (size > 1)
	{
		delete_content(trav_node->prev->content);
		*trav_node->prev = (t_node){NULL, NULL, NULL};
		free(trav_node->prev);
		trav_node = trav_node->next;
		--size;
	}
	delete_content(list->tail->content);
	*list->tail = (t_node){NULL, NULL, NULL};
	free(list->tail);
	*list = (t_dlist){NULL, NULL, NULL, 0, 0, 0};
}

void	pop_front(t_dlist *list, void (*delete_content)(void *))
{
	t_node	*del_node;

	if (list->head == NULL)
		return ;
	del_node = list->head;
	list->head = list->head->next;
	if (list->head != NULL)
		list->head->prev = NULL;
	else
		list->tail = NULL;
	delete_content(del_node->content);
	free(del_node);
	--list->size;
}

void	pop_back(t_dlist *list, void (*delete_content)(void *))
{
	t_node	*del_node;

	if (list->tail == NULL)
		return ;
	del_node = list->tail;
	list->tail = list->tail->prev;
	if (list->tail != NULL)
		list->tail->next = NULL;
	else
		list->head = NULL;
	delete_content(del_node->content);
	free(del_node);
	--list->size;
}

t_node	*erase_at(t_dlist *list, t_node *at, void (*delete_content)(void *))
{
	t_node		*trav;

	if (at == list->head)
	{
		pop_front(list, delete_content);
		return (list->head);
	}
	else if (at == list->tail)
	{
		pop_back(list, delete_content);
		return (NULL);
	}
	trav = list->head;
	while (trav && trav != at)
		trav = trav->next;
	if (trav == NULL)
		return (NULL);
	trav = trav->next;
	at->prev->next = at->next;
	at->next->prev = at->prev;
	delete_content(at->content);
	*at = (t_node){NULL, NULL, NULL};
	free(at);
	--list->size;
	return (trav);
}
