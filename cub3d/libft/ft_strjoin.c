/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:09:12 by hseong            #+#    #+#             */
/*   Updated: 2022/06/18 19:18:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ret;
	char		*temp;
	int			idx;

	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	temp = ret;
	idx = 0;
	while (s1[idx])
		*temp++ = s1[idx++];
	idx = 0;
	while (s2[idx])
		*temp++ = s2[idx++];
	*temp = 0;
	return (ret);
}
