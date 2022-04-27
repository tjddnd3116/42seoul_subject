/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:09:40 by soum              #+#    #+#             */
/*   Updated: 2022/04/27 18:42:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_hpp
#define whatever_hpp

template<typename T1>
void swap(T1& a, T1& b)
{
	T1 tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T1>
T1 min(const T1& a, const T1& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T1>
T1 max(const T1& a, const T1& b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
