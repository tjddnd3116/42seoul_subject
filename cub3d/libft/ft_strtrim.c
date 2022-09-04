/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:29:06 by hseong            #+#    #+#             */
/*   Updated: 2022/05/20 18:33:48 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// this has similar behaivor as java's one.
char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	size_t		right;
	size_t		left;

	right = 0;
	left = 0;
	while (s1[right] && ft_strchr(set, s1[right]))
		++right;
	left = right;
	while (s1[right])
		++right;
	while (left < right && ft_strchr(set, s1[right]))
		--right;
	ret = ft_strndup(s1 + left, right - left + 1);
	if (!ret)
		return (NULL);
	return (ret);
}
