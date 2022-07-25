/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:25:20 by soum              #+#    #+#             */
/*   Updated: 2021/07/15 19:04:08 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	now = *lst;
	while (now)
	{
		next = now->next;
		del(now->content);
		free(now);
		now = next;
	}
	*lst = NULL;
}
