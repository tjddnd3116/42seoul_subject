/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:25:35 by hseong            #+#    #+#             */
/*   Updated: 2022/08/07 13:21:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dlinkedlist.h"

t_dlist	*dlist_duplicate(t_dlist *list, void *(*copy_content)(void *))
{
	t_dlist		*clone;
	size_t		size;
	size_t		idx;

	clone = dlist_init();
	size = list->size;
	idx = 0;
	list->cur = list->head;
	while (idx < size)
	{
		push_back(clone, copy_content(list->cur->content));
		move_back(list);
		++idx;
	}
	list->cur = NULL;
	return (clone);
}
