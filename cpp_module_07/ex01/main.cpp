/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:48:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/27 19:02:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void)
{
	int i_arr[3] = {1, 2, 3};

	::iter(i_arr, sizeof(i_arr) / sizeof(*i_arr), ::print_val);
	::iter(i_arr, sizeof(i_arr) / sizeof(*i_arr), ::print_addr);


	std::string s_arr[5] = {"a", "b", "c", "d", "e"};

	::iter(s_arr, sizeof(s_arr) / sizeof(*s_arr), ::print_val);
	::iter(s_arr, sizeof(s_arr) / sizeof(*s_arr), ::print_addr);

	const float f_arr[10] = {0,};

	::iter(f_arr, sizeof(f_arr) / sizeof(*f_arr), ::print_val);
	::iter(f_arr, sizeof(f_arr) / sizeof(*f_arr), ::print_addr);

	char c_arr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	::iter(c_arr, sizeof(c_arr) / sizeof(*c_arr), ::print_val);
	::iter(c_arr, sizeof(c_arr) / sizeof(*c_arr), ::print_addr);

	return (0);
}
