/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:59:11 by soum              #+#    #+#             */
/*   Updated: 2021/11/24 13:59:23 by soum             ###   ########.fr       */
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

typedef struct s_info
{
	t_stack *a_stack;
	t_stack *b_stack;
	int		pa_count;
	int		pb_count;
	int		ra_count;
	int		rb_count;
	int		write_flag;
}	t_info;

//util.c
long long	ft_atoi2(const char *str);
int			stack_size(t_stack *stack);
//libft
void		ft_putstr_fd(char *s, int fd);
int			ft_isspace(const char c);
//error.c
void		error_msg_exit(char *msg);
void		malloc_error(t_info *info);
void		free_stack(t_info *info);
//sort.c
void		sorting(t_info *info);
//swap.c
void		swap_a(t_info *info);
void		swap_b(t_info *info);
void		swap_all(t_info *info);
//push.c
void		push_a(t_info *info);
void		push_b(t_info *info);
void		push_all(t_info *info);
//rotate.c
void		rotate_a(t_info *info);
void		rotate_b(t_info *info);
void		rotate_all(t_info *info);
//reverse.c
void		reverse_a(t_info *info);
void		reverse_b(t_info *info);
void		reverse_all(t_info *info);
t_node		*last_stack(t_stack *stack);
//pop_push.c
void		pop(t_stack *stack);
int			push(int data, t_stack *stack);
int			push_last(int data, t_stack *stack);
void		pop_last(t_stack *stack);
//size_sort.c
void		size_2_sort(t_info *info);
void		size_3_sort(t_info *info);
void		size_4_sort(t_info *info);
void		size_5_sort(t_info *info);
//sort_util.c
int			find_min_num(t_node *node, int size);
int			find_min_locate(t_node *node, int size);
int			find_max_num(t_node *node, int size);
int			find_max_locate(t_node *node, int size);
//sort_util2.c
int			big_pivot(t_stack *stack, int size);
int			small_pivot(t_stack *stack, int size);
void		init_count(t_info *info);
//quick_sort.c
void		over_5_sort(t_info *info);
void		a_to_b(t_info *info, int size);
void		b_to_a(t_info *info, int size);
void		under_3_sort(t_info *info, int size, char stack);
//quick_sort2.c
void		rrr(t_info *info, int ra, int rb);
void		recursive(t_info *info, int flag);
//sort.c
void		test_print(t_info *info);
#endif
