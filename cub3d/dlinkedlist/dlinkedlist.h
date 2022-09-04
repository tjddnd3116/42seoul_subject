/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:45:48 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 14:45:48 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLINKEDLIST_H
# define DLINKEDLIST_H

# include <stddef.h>
# include <stdio.h>

typedef int	(*t_comp)(const void *, const void *);

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_dlist
{
	t_node		*head;
	t_node		*tail;
	t_node		*cur;
	size_t		size;
	size_t		idx;
	int			flag;
}				t_dlist;

t_dlist	*dlist_init(void);
void	dlist_local_init(t_dlist *list);

// CREATE AND DELETE
int		push_front(t_dlist *list, void *content);
int		push_back(t_dlist *list, void *content);
int		insert_at(t_dlist *list, t_node *at, void *content);
void	pop_front(t_dlist *list, void (*delete_content)(void *));
void	pop_back(t_dlist *list, void (*delete_content)(void *));
t_node	*erase_at(t_dlist *list, t_node *at, void (*delete_content)(void *));
void	pop_node(t_dlist *list, t_node *del_node,
			void (*delete_content)(void *));

void	dlist_delete(t_dlist *list, void (*delete_content)(void *));
void	dlist_empty(t_dlist *list, void (*delete_content)(void *));
void	*dlist_to_array(t_dlist *list, void *(*extract_contetn)(void *));
void	array_to_dlist(t_dlist *list, const void *arr,
			size_t size, size_t count);
t_dlist	*array_to_dlist_init(const void *arr, size_t size, size_t count);

// UPDATE cur
void	move_front(t_dlist *list);
void	move_back(t_dlist *list);
void	set_cur(t_dlist *list, void *content);

// READ
void	peek_front(t_dlist *list, void (*delete_content)(void *));
void	peek_back(t_dlist *list, void (*delete_content)(void *));
void	*get_front(t_dlist *list);
void	*get_back(t_dlist *list);
void	dlist_print_forward(t_dlist *list, void (*print_content)(void *));
void	dlist_print_backward(t_dlist *list, void (*print_content)(void *));

// utils
void	ft_putnbr_space(int num);
void	dlist_mergesort(t_dlist *list, t_comp comp);
t_dlist	*dlist_duplicate(t_dlist *list, void *(*copy_content)(void *));
t_node	*dlist_find_content(t_dlist *list, const void *content, size_t size,
			void *(*extract_contetn)(void *));
void	*ft_memcpy(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);

#endif
