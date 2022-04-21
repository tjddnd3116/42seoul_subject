/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:59:04 by soum              #+#    #+#             */
/*   Updated: 2022/04/21 18:02:45 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_hpp
#define Intern_hpp

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
		private:
		public:
			// Orthodox Canonical Form
			Intern();
			Intern( const Intern& intern );
			Intern& operator=( const Intern& intern );
			~Intern();
			// member fucntions
			Form* makeForm( const std::string& name, const std::string& target);
};
#endif
