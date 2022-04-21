/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:30 by soum              #+#    #+#             */
/*   Updated: 2022/04/22 00:44:45 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>


int main(void)
{
	try {
	// < bureaucrat grade test >
	Bureaucrat soum("soum", 1);
	std::cout << soum << std::endl;
	// Bureaucrat bob("bob", 0); 		// grade is too high
	// Bureaucrat tom("tom", 151); // grade is too low

	// < form grade test >
	Form form1("form1", 10,10);
	std::cout << form1 << std::endl;
	// Form form2("form2", 0,10); 		// sign grade is too high
	// Form form3("form3", 10,0);		// execute grade is too high
	// Form form4("form4", 151,42);	// sign grade is too low
	// Form form5("form5", 42,151);	// execute grade is too low

	// < sign test >
	Bureaucrat john("john", 42);
	std::cout << john << std::endl;
	Form form7("form7", 42, 50);
	std::cout << form7 << std::endl;
	john.signForm(form7);
	std::cout << form7 << std::endl;

	Form form8("form8", 41, 70);
	std::cout << form8 << std::endl;
	john.signForm(form8);			// john grade is lower than form sign grade
	std::cout << form8 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
