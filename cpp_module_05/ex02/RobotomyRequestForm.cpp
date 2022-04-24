/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:25:25 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 15:18:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	:Form("RobotomyRequestForm", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf)
	:Form(rrf)
{
	*this = rrf;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	setTarget(rrf.getTarget());
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
		// std::string rnd_num_str = "1234"; // for valgrind test
		std::cout << "##################################" << std::endl;
		std::cout << "########## drill noise ###########" << std::endl;
		std::cout << "##################################" << std::endl;
		if (rnd_num_str.at(3) % 2)
			std::cout << getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << getTarget() << " has been robotomized fail" << std::endl;
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
	}
}
