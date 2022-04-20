/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:25:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 17:29:20 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	:Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf)
	:Form(rrf)
{
	_target = rrf.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	std::cout << "really do you want copy only sign of " << rrf.getName() \
		<< "?? \n\033[30myou can't do that!\033[0m" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw NoSignedException("It's not signed yet");
	if (bureaucrat.getGrade() > getGradeExec())
		throw GradeTooLowException("bureaucrat grade is too lower than form execute grade");
	else
	{
		char *rnd_addr;
		std::string rnd_num_str = std::to_string((unsigned int)(long)(&rnd_addr)*(unsigned int)(long)(&rnd_addr));
		std::cout << "########## drill noise ###########" << std::endl;
		if (rnd_num_str.at(4) % 2)
			std::cout << getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << getTarget() << " has been robotomized fail" << std::endl;
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
	}
}

const std::string RobotomyRequestForm::getTarget( void ) const
{
	return (_target);
}
