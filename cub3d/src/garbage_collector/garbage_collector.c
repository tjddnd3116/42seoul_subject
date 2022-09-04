/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:42 by soum              #+#    #+#             */
/*   Updated: 2022/09/04 15:07:42 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "garbage_collector.h"

t_garbage	*get_garbage_ptr(void)
{
	static t_garbage	bucket;

	return (&bucket);
}

void	collect_fd_garbage(int fd)
{
	t_garbage	*bucket;

	bucket = get_garbage_ptr();
	bucket->fd = fd;
}

void	collect_ptr_garbage(void *ptr)
{
	t_garbage	*bucket;

	bucket = get_garbage_ptr();
	bucket->ptr = ptr;
}

void	collect_ptr_2d_garbage(void **ptr_2d)
{
	t_garbage	*bucket;

	bucket = get_garbage_ptr();
	bucket->ptr_2d = ptr_2d;
}

void	dump_garbage(void)
{
	t_garbage	*bucket;
	void		**temp;

	bucket = get_garbage_ptr();
	if (bucket->fd > 0)
		close(bucket->fd);
	free(bucket->ptr);
	temp = bucket->ptr_2d;
	if (temp == NULL)
		return ;
	while (*temp)
	{
		free(*temp);
		++temp;
	}
	free(bucket->ptr_2d);
}
