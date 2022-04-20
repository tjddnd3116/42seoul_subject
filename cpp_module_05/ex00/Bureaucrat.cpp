/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 10:23:01 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat( std::string name, int grade )
	:_name(name)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
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
	if (_grade - grade < 1)
		throw GradeTooHighException();
	else
		_grade -= grade;
}

void Bureaucrat::decrement( int grade )
{
	if (_grade + grade > 150)
		throw GradeTooLowException();
	else
		_grade += grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
