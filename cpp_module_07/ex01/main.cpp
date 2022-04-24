/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:48:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 18:58:42 by soum             ###   ########.fr       */
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


	return (0);
}
