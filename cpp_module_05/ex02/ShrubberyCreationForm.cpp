/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:30:14 by soum              #+#    #+#             */
/*   Updated: 2022/04/23 13:56:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_ascii_tree =\
"                                                         .\n"
"                                              .         ;\n"
"                 .              .              ;%     ;;\n"
"                   ,           ,                :;%  %;\n"
"                    :         ;                   :;%;'     .,\n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'\n"
"                       `@%.  `;@%.      ;@@%;\n"
"                          `@%%. `@%%    ;@@%;\n"
"                            ;@%. :@%%  %@@%;\n"
"                              %@bd%%%bd%%:;\n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '\n"
"                                %@@@o%;:(.,'\n"
"                            `.. %@@@o%::;\n"
"                               `)@@@o%::;\n"
"                                %@@(o)::;\n"
"                               .%@@@@%::;\n"
"                               ;%@@@@%::;.\n"
"                              ;%@@@@%%:;;;.\n"
"                          ...;%@@@@@%%:;;;;,..    Gilo97\n";

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	:Form("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf)
	:Form(scf)
{
	*this = scf;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	setTarget(scf.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw NoSignedException("It's not signed yet");
	if (bureaucrat.getGrade() > getGradeExec())
		throw GradeTooLowException("bureaucrat grade is too lower than form execute grade");
	else
	{
		std::ofstream writeFile;

		writeFile.open((getTarget() + "_shrubbery").c_str());
		if (writeFile.is_open())
			writeFile.write(_ascii_tree.c_str(), _ascii_tree.length());
		writeFile.close();
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
	}
}
