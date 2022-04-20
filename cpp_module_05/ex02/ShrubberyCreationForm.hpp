/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:28:08 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 15:57:47 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_hpp
#define ShrubberyCreationForm_hpp

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
		private:
			std::string _target;
			static const std::string _ascii_tree;
		public:
			// Orthodox Canonical Form
			ShrubberyCreationForm( std::string target );
			ShrubberyCreationForm( const ShrubberyCreationForm& );
			ShrubberyCreationForm& operator=( const ShrubberyCreationForm& scf );
			~ShrubberyCreationForm();
			// overriding virtual funtions
			void execute( Bureaucrat const & bureaucrat ) const;
			const std::string getTarget( void ) const;
};
#endif
