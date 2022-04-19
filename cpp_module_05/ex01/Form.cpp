/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:01:59 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 07:32:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <ostream>

Form::Form(const std::string name, int grade_sign, int grade_exec)
	:_name(name), _gradeSign(grade_sign), _gradeExec(grade_exec)
{
	_isSigned = false;
}

Form::Form( const Form& form )
	:_name(form.getName()),_isSigned(form.getIsSigned()),\
		 _gradeSign(form.getGradeSign()), _gradeExec(form.getGradeExec())
{}

Form& Form::operator=(const Form &from)
{
	_isSigned = false;
	return (*this);
}

Form::~Form()
{}

std::string Form::getName( void ) const
{
	return (_name);
}

bool Form::getIsSigned( void ) const
{
	return (_isSigned);
}

int Form::getGradeSign( void ) const
{
	return (_gradeSign);
}

int Form::getGradeExec( void ) const
{
	return (_gradeExec);
}
void Form::beSigned( const Bureaucrat& bureaucrat)
{
	try {
		
	} catch (declaration) {
	statements
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low");
}

std::ostream& operator<<( std::ostream &os, const Form& form )
{
	os << "name : " << form.getName() << std::endl;
	os << "is signed : " << form.getIsSigned() << std::endl;
	os << "grade required to sign : " << form.getGradeSign() << std::endl;
	os << "grade required to execute : " << form.getGradeExec() << std::endl;
	return (os);
}
