/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:07:44 by soum              #+#    #+#             */
/*   Updated: 2022/09/07 18:06:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_garbage
{
	int		fd;
	void	*ptr;
	void	**ptr_2d;
}	t_garbage;

t_garbage	*get_garbage_ptr(void);
void		collect_fd_garbage(int fd);
void		collect_ptr_garbage(void *ptr);
void		collect_ptr_2d_garbage(void **ptr_2d);
void		dump_garbage(void);

#endif
