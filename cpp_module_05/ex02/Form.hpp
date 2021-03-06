/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:01:59 by soum              #+#    #+#             */
/*   Updated: 2022/04/23 13:49:05 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_hpp
#define Form_hpp

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <iomanip>

class Form
{
		private:
			const std::string _name;
			bool _isSigned;
			const int _gradeSign;
			const int _gradeExec;
			std::string _target;
			void checkGrade( int grade , const std::string grade_type ) const;

		public:
			// Orthodox Canonical Form
			Form( const std::string name, int grade_sign, int grade_exec);
			Form( const Form& from );
			Form& operator=( const Form& from );
			virtual ~Form();
			// getter
			std::string getName( void ) const;
			bool getIsSigned( void ) const;
			int getGradeSign( void ) const;
			int getGradeExec( void ) const;
			std::string getTarget( void ) const;
			// setter
			void setTarget( const std::string target );
			// member fucntions
			void beSigned( Bureaucrat& bureaucrat );
			// pure virtual funtions
			virtual void execute( Bureaucrat const & bureaucrat ) const = 0;
			// exception class implement inheritance std::exception
			class GradeTooHighException : public std::exception{
					std::string _errMsg;
				public:
					GradeTooHighException( const std::string err_msg );
					~GradeTooHighException() throw();
					const char* what() const throw();
			};
			class GradeTooLowException : public std::exception{
					std::string _errMsg;
				public:
					GradeTooLowException( const std::string err_msg );
					~GradeTooLowException() throw();
					const char* what() const throw();
			};
			class NoSignedException : public std::exception{
					std::string _errMsg;
				public:
					NoSignedException( const std::string err_msg );
					~NoSignedException() throw();
					const char* what() const throw();
			};
};

std::ostream& operator<<( std::ostream &os, const Form& form );
#endif
