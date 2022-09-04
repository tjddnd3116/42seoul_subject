/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvpe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:01:20 by hseong            #+#    #+#             */
/*   Updated: 2022/06/28 23:49:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/errno.h>

#define MAX_PATHNAME (1024)

void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

int	ft_execvpe(const char *filename, char *const *argv, char *const *envp,
	char **path_arr)
{
	char	fullpath[MAX_PATHNAME + 1];
	size_t	path_len;

	if (path_arr == NULL)
		return (ENOENT);
	while (*path_arr != NULL)
	{
		ft_memset(fullpath, 0, MAX_PATHNAME + 1);
		path_len = ft_strlen(*path_arr);
		ft_strlcpy(fullpath, *path_arr, path_len + 1);
		if (fullpath[path_len - 1] != '/')
			fullpath[path_len] = '/';
		ft_strlcat(fullpath, filename, MAX_PATHNAME + 1);
		execve(fullpath, argv, envp);
		++path_arr;
	}
	return (-1);
}
