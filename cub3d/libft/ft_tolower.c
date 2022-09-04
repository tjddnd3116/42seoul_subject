/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:07:53 by hseong            #+#    #+#             */
/*   Updated: 2021/11/17 15:17:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// it has different behavior compared to linux.
// c cast to unsigned char in linux, but not in macOS.
int	ft_tolower(int c)
{
	return (c + 32 * (c > 64 && c < 91));
}
