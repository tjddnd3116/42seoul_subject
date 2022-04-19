/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:49 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 07:24:07 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <exception>
#include <iostream>

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
		void increment( void );
		void decrement( void );
		// exception class implement inheritance std::exception
		class GradeTooHighException : public std::exception{
			const char* what() const throw(); };
		class GradeTooLowException : public std::exception{
			const char* what() const throw(); };
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif
