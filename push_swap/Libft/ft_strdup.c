/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:19:44 by soum              #+#    #+#             */
/*   Updated: 2021/05/29 16:12:32 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	s1_len;
	int		index;

	index = 0;
	s1_len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (tmp == 0)
		return (NULL);
	while (s1[index])
	{
		tmp[index] = *(s1 + index);
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}
