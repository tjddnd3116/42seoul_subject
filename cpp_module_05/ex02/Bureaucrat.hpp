/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:49 by soum              #+#    #+#             */
/*   Updated: 2022/04/22 21:35:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat ( std::string name, int grade );
		Bureaucrat ( const Bureaucrat& bureaucrat );
		Bureaucrat& operator=( const Bureaucrat& bureaucrat );
		~Bureaucrat();
		// getter
		std::string getName( void ) const;
		int getGrade( void ) const;
		// member funtions
		void increment( int grade );
		void decrement( int grade );
		void signForm( Form* form );
		void executeForm( Form const & form );
		// exception class implement inheritance std::exception
		class GradeTooHighException : public std::exception{
			const char* what() const throw(); };
		class GradeTooLowException : public std::exception{
			const char* what() const throw(); };
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif
