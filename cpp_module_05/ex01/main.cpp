/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:30 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 06:51:46 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>


int main(void)
{
	try {
	Bureaucrat soum("soum", 149);
	std::cout << soum << std::endl;
	soum.decrement();
	std::cout << soum << std::endl;
	soum.decrement();
	std::cout << soum << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
	return (0);
}
