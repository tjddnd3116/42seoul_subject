/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:24:17 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 15:45:30 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form
{
		private:
			std::string _target;
		public:
			// Orthodox Canonical Form
			RobotomyRequestForm( std::string target );
			RobotomyRequestForm( const RobotomyRequestForm& rrf );
			RobotomyRequestForm& operator= ( const RobotomyRequestForm& rrf );
			~RobotomyRequestForm();
			// overriding virtual funtions
			void execute( Bureaucrat const & bureaucrat ) const;
			// getter
			const std::string getTarget( void ) const;
};
#endif
