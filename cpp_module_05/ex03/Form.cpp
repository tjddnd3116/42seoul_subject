/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:01:59 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 14:13:49 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iomanip>

Form::Form(const std::string name, int grade_sign, int grade_exec)
	:_name(name), _gradeSign(grade_sign), _gradeExec(grade_exec)
{
	_isSigned = false;
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException("sign grade or execute grade is too high correct grade is [1] to [150]");
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException("sign grade or execute grade is too low correct grade is [1] to [150]");
}

Form::Form( const Form& form )
	:_name(form.getName()),_isSigned(form.getIsSigned()),\
		 _gradeSign(form.getGradeSign()), _gradeExec(form.getGradeExec())
{}

Form& Form::operator=(const Form &form)
{
	std::cout << "really do you want copy only sign of " << form.getName() \
		<< "?? \n\033[30myou can't do that!\033[0m" << std::endl;
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
void Form::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException("bureaucrat grade is too lower than form sign grade");
	else
		_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException( const std::string err_msg )
	:_errMsg(err_msg)
{}

const char* Form::GradeTooHighException::what() const throw()
{
	return (_errMsg.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

Form::GradeTooLowException::GradeTooLowException( const std::string err_msg )
	:_errMsg(err_msg)
{}

const char* Form::GradeTooLowException::what() const throw()
{
	return (_errMsg.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

Form::NoSignedException::NoSignedException( const std::string err_msg )
	:_errMsg(err_msg)
{}

const char* Form::NoSignedException::what() const throw()
{
	return (_errMsg.c_str());
}

Form::NoSignedException::~NoSignedException() throw()
{}

std::ostream& operator<<( std::ostream &os, const Form& form )
{
	int len = form.getName().length();
	os << "\033[33m";
	os << std::setw(32 + len) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
	os << std::setw(27)<< std::left << "| name" << " : " << std::setw(len) << form.getName() << " |" << std::endl;
	if (form.getIsSigned())
		os << std::setw(27) << "| sign" << " : " << "\033[34m" << std::setw(len) << "true" << "\033[33m" << " |" << std::endl;
	else
		os << std::setw(27) << "| sign" << " : " << "\033[31m" << std::setw(len) << "false" << "\033[33m" << " |" << std::endl;
	os << std::setw(27) << "| grade required to sign" << " : " << std::setw(len) << form.getGradeSign() << " |" << std::endl;
	os << std::setw(27) << "| grade required to execute"<< " : " << std::setw(len) << form.getGradeExec() << " |"<< std::endl;
	os << std::setw(32 + len) << std::setfill('-') << " " << std::setfill(' ');
	os << "\033[0m";
	return (os);
}
