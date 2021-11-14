/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:59:11 by soum              #+#    #+#             */
/*   Updated: 2021/11/14 17:19:33 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	struct s_node	*pre;
	struct s_node	*next;
	int		data;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

//util.c
long long	ft_atoi2(const char *str);
int			stack_size(t_stack *stack);
//ft_atoi.c
int			ft_isspace(const char c);
//error.c
void		error_msg_exit(char *msg);
void		malloc_error(t_stack *a);
void		free_stack(t_stack *a);
//sort.c
void		sorting(t_stack *a, t_stack *b);
//swap.c
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		swap_all(t_stack *a, t_stack *b);
//push.c
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		push_all(t_stack *a, t_stack *b);
//rotate.c
void		rotate_a(t_stack *a, t_stack *b);
void		rotate_b(t_stack *a, t_stack *b);
void		rotate_all(t_stack *a, t_stack *b);
//reverse.c
void		reverse_a(t_stack *a, t_stack *b);
void		reverse_b(t_stack *a, t_stack *b);
void		reverse_all(t_stack *a, t_stack *b);
t_node		*last_stack(t_stack *stack);
//pop_push.c
void		pop(t_stack *stack);
int			push(int data, t_stack *stack);
int			push_last(int data, t_stack *stack);
void		pop_last(t_stack *stack);
//size_sort.c
void		size_3_sort(t_stack *a, t_stack *b);
void		size_5_sort(t_stack *a, t_stack *b);
#endif
