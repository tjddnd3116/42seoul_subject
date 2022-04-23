/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:41:55 by soum              #+#    #+#             */
/*   Updated: 2022/04/23 13:56:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	:Form("PresidentialPardonForm", 25, 5)
{
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& ppf )
	:Form(ppf)
{
	*this = ppf;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &ppf )
{
	setTarget(ppf.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute( Bureaucrat const &bureaucrat ) const
{
	if (!this->getIsSigned())
		throw NoSignedException("It's not signed yet");
	if (bureaucrat.getGrade() > getGradeExec())
		throw GradeTooLowException("bureaucrat grade is too lower than form execute grade");
	else
	{
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;;
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
	}
}
