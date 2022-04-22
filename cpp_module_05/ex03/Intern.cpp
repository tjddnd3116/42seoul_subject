/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:59:03 by soum              #+#    #+#             */
/*   Updated: 2022/04/22 20:40:40 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	_formNameArr[0] = "robotomy request";
	_formNameArr[1] = "presidential pardon";
	_formNameArr[2] = "shrubbery creation";
}

Intern::Intern( const Intern& intern )
{
	*this = intern;
}

Intern& Intern::operator=( const Intern& intern )
{
	(void)intern;
	return (*this);
}

Intern::~Intern()
{}

Form* Intern::makeForm( const std::string& name, const std::string& target)
{
	Form *form[3];

	form[0] = new RobotomyRequestForm(target);
	form[1] = new PresidentialPardonForm(target);
	form[2] = new ShrubberyCreationForm(target);
	try {
		for (int i = 0; i < 3; i++)
		{
			if (name == _formNameArr[i])
			{
				delete form[(i + 1) % 3];
				delete form[(i + 2) % 3];
				return (form[i]);
			}
		}
		throw 1;
	}catch(int err_idx){
		std::cout << "can't find " << name << " form" << std::endl;
		delete form[0];
		delete form[1];
		delete form[2];
		return (NULL);
	}
}
