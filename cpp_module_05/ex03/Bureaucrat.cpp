/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/22 20:25:27 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

Bureaucrat::Bureaucrat( std::string name, int grade )
	:_name(name)
{
	try {
	if (grade <= 0)
	{
		_grade = 1;
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		_grade = 150;
		throw GradeTooLowException();
	}
	else
		_grade = grade;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat ( const Bureaucrat& bureaucrat )
	:_name(bureaucrat.getName())
{
	*this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& bureaucrat )
{
	_grade = bureaucrat.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName( void ) const
{
	return (_name);
}

int Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

void Bureaucrat::increment( int grade )
{
	try {
		if (_grade - grade < 1)
		{
			grade = 1;
			throw GradeTooHighException();
		}
		else
			_grade -= grade;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrement( int grade )
{
	try {
	if (_grade + grade > 150)
	{
		grade = 150;
		throw GradeTooLowException();
	}
	else
		_grade += grade;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
void Bureaucrat::signForm( Form& form )
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << getName() << " coudn't sign " << form.getName() \
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( Form const & form )
{
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << getName() << " coudn't execute " << form.getName() \
			<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("bureaucrat grade is too high, correct grade is [1] to [150] so your grade be [1]");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("bureaucrat grade is too low correct grade is [1] to [150] so your grade be [150]");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
