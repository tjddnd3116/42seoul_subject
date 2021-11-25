#include "../includes/push_swap.h"
#include <stdio.h>

void	test_print(t_info *info)
{
	t_node *a_tmp;
	t_node *b_tmp;
	int		a_size;
	int		b_size;

	a_tmp = info->a_stack->top;
	b_tmp = info->b_stack->top;
	a_size = stack_size(info->a_stack);
	b_size = stack_size(info->b_stack);
	printf("-----------------\n");
	while (a_tmp != NULL || b_tmp != NULL)
	{
		if (a_tmp != NULL)
		{
			printf("%d ", a_tmp->data);
			a_tmp = a_tmp->next;
		}
		else if (a_tmp == NULL)
			printf("  ");
		if (b_tmp != NULL)
		{
			printf("%d\n", b_tmp->data);
			b_tmp = b_tmp->next;
		}
		else if(b_tmp == NULL)
			printf("  \n");
	}
	printf("a b\n");
	printf("%d %d\n", a_size, b_size);
	printf("-----------------\n");
}
