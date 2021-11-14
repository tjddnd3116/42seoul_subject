/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:57:18 by soum              #+#    #+#             */
/*   Updated: 2021/11/14 15:28:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	dup_check(t_node *tmp, int num, t_stack *a)
{
	while (tmp != NULL)
	{
		if (tmp->data == num)
		{
			free_stack(a);
			error_msg_exit("Error\n");
		}
		else
			tmp = tmp->next;
	}
}

t_stack	*create_linked_list(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		exit(0);
	new->top = NULL;
	return (new);
}

int	check_num(char *num_str, t_stack *a)
{
	long long	num;
	int			index;
	t_node		*tmp;

	tmp = a->top;
	index = 0;
	while (num_str[index] != '\0')
	{
		if ((num_str[index] >= '0' && num_str[index] <= '9') \
				|| (num_str[index] == '+' || num_str[index] == '-'))
			index++;
		else
		{
			free_stack(a);
			error_msg_exit("Error\n");
		}
	}
	num = ft_atoi2(num_str);
	if (num < -2147483648 || num > 2147483647)
	{
		free_stack(a);
		error_msg_exit("Error");
	}
	dup_check(tmp, num, a);
	return ((int)num);
}

void	insert_stack(char *num_str, t_stack *a)
{
	int		num;
	t_node	*new_node;
	t_node	*tmp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		malloc_error(a);
	num = check_num(num_str, a);
	tmp = a->top;
	if (tmp == NULL)
	{
		a->top = new_node;
		new_node->data = num;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->pre = tmp;
		new_node->next = NULL;
		new_node->data = num;
	}
}

int	main(int argc, char **argv)
{
	int		index;
	t_stack	*a;
	t_stack	*b;

	index = 0;
	a = create_linked_list();
	b = create_linked_list();
	if (argc > 1)
	{
		while (++index < argc)
			insert_stack(argv[index], a);
		sorting(a, b);
	}
	else
	{
		free_stack(a);
		free_stack(b);
	}
}
