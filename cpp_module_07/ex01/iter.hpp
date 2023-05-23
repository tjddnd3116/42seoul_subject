/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:48:19 by soum              #+#    #+#             */
/*   Updated: 2023/01/20 23:03:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
#define iter_hpp

#include <iostream>
#include <exception>

template <typename T>
void iter(const T* addr, unsigned long long len, void(*f)(const T&))
{
	if (addr == NULL || f == NULL)
		return ;
	for (unsigned long long i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void iter(const T* addr, unsigned long long len, void(*f)(T&))
{
	if (addr == NULL || f == NULL)
		return ;
	for (unsigned long long i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void print_val( const T& a)
{
	std::cout << a << std::endl;
}

template <typename T>
void print_addr( const T& a )
{
	std::cout << &a << std::endl;
}

template <>
inline void print_addr( const char& a )
{
	std::cout << (void*)&a << std::endl;
}

#endif
