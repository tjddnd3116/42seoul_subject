/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:05:38 by hseong            #+#    #+#             */
/*   Updated: 2021/11/17 16:01:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check s == NULL case in MacOS
char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*ret;

	size = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	while (*s)
		*ret++ = *s++;
	*ret = 0;
	return (ret - size);
}
