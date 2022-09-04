/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_peek.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 06:51:51 by hseong            #+#    #+#             */
/*   Updated: 2022/06/09 20:59:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "dlinkedlist.h"

void	peek_front(t_dlist *list, void (*print_content)(void *))
{
	if (list->size == 0)
		return ;
	print_content(list->head->content);
}

void	peek_back(t_dlist *list, void (*print_content)(void *))
{
	if (list->size == 0)
		return ;
	print_content(list->tail->content);
}

void	*get_front(t_dlist *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->head->content);
}

void	*get_back(t_dlist *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->tail->content);
}
