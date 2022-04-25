/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:48:19 by soum              #+#    #+#             */
/*   Updated: 2022/04/25 13:49:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
#define iter_hpp

#include <iostream>
#include <exception>

template <typename T>
void iter(T* addr, unsigned long long len, void(*f)(T*))
{
	if (addr == NULL || f == NULL)
		return ;
	for (unsigned long long i = 0; i < len; i++)
		f(&addr[i]);
}

template <typename T>
void print_val(T* a)
{
	std::cout << *a << std::endl;
}

template <typename T>
void print_addr(T* a)
{
	std::cout << a << std::endl;
}

#endif
