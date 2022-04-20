/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:59:03 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 20:00:27 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	_brain = "...";
}

Intern::Intern( const Intern& intern )
{
	*this = intern;
}

Intern& Intern::operator=( const Intern& intern )
{
	_brain = intern.getBrain();
	return (*this);
}

Intern::~Intern()
{}

Form* Intern::makeForm( const std::string& name, const std::string& target)
{
	std::string form_name_arr[3];
	Form *form[3];

	form[0] = new RobotomyRequestForm(target);
	form[1] = new PresidentialPardonForm(target);
	form[2] = new ShrubberyCreationForm(target);
	form_name_arr[0] = "robotomy request";
	form_name_arr[1] = "presidential pardon";
	form_name_arr[2] = "shrubbery creation";

	try {
		for (int i = 0; i < 3; i++)
		{
			if (name == form_name_arr[i])
			{
				delete form[(i + 1) % 3];
				delete form[(i + 2) % 3];
				return (form[i]);
			}
		}
		throw 1;
	}catch(int error_code){

		std::cout << "can't find " << name << " form" << std::endl;
		delete form[0];
		delete form[1];
		delete form[2];
	}
	return (NULL);
}

std::string Intern::getBrain( void ) const
{
	return (_brain);
}
