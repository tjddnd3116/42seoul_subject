/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:30 by soum              #+#    #+#             */
/*   Updated: 2022/04/23 16:10:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main(void)
{
	// < subject test >
	Bureaucrat aaa("aaa", 40);
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("presidential pardo", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		aaa.signForm(rrf);
		aaa.executeForm(*rrf);
	}

	delete rrf;

	// <  form status test >
	// Form *form1 = new PresidentialPardonForm("target1");
	// std::cout << *form1 << std::endl;
	// Form *form2 = new RobotomyRequestForm("target2");
	// std::cout << *form2 << std::endl;
	// Form *form3 = new ShrubberyCreationForm("target3");
	// std::cout << *form3 << std::endl;
    //
	// < sign test >
	// Bureaucrat soum("soum", 50);
	// soum.signForm(form1); // can't sign it
	// soum.signForm(form2); // can sign it
	// soum.signForm(form3); // can sign it
    //
	// std::cout << *form1 << std::endl;
	// std::cout << *form2 << std::endl;
	// std::cout << *form3 << std::endl;

	// < execute test>
	// 1. all signed
	// Bureaucrat test1("test1", 1);
	// test1.signForm(form1);
	// std::cout << *form1 << std::endl;
	// test1.signForm(form2);
	// std::cout << *form2 << std::endl;
	// test1.signForm(form3);
	// std::cout << *form3 << std::endl;
    //
	// test1.executeForm(*form1);
	// test1.executeForm(*form2);
	// test1.executeForm(*form3);

	// 2. grade lower than execute grade
	// Bureaucrat test2("test2", 150);
	// test2.executeForm(*form1);
	// test2.executeForm(*form2);
	// test2.executeForm(*form3);
    //
	// delete form1;
	// delete form2;
	// delete form3;
    //
	// // 3. not signed
	// Form *form4 = new PresidentialPardonForm("target4");
	// Form *form5 = new PresidentialPardonForm("target5");
	// Form *form6 = new PresidentialPardonForm("target6");
    //
	// test1.executeForm(*form4);
	// test1.executeForm(*form5);
	// test1.executeForm(*form6);
    //
	// delete form4;
	// delete form5;
	// delete form6;

	return (0);
}
