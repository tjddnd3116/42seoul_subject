/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:14:44 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 22:36:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& a, int num)
{
	typename T::iterator tmp;

	tmp = std::find(a.begin(), a.end(), num);
	if (tmp == a.end())
		throw std::runtime_error("can't find num");
	return (tmp);
}
