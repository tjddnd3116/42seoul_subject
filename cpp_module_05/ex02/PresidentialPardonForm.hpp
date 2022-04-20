/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:41:54 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 13:45:39 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_hpp
#define PresidentialPardonForm_hpp

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
		private:
			std::string _target;
		public:
			// Orthodox Canonical Form
			PresidentialPardonForm( const std::string& target );
			PresidentialPardonForm( const PresidentialPardonForm& ppf );
			PresidentialPardonForm& operator= ( const PresidentialPardonForm& ppf );
			~PresidentialPardonForm();
			// overriding virtual funtions
			void execute( Bureaucrat const & bureaucrat ) const;
			// getter
			const std::string getTarget( void ) const;

};
#endif
