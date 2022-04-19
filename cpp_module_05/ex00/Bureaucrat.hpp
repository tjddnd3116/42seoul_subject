/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:49 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 18:59:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int grade;

	public:
		// getter
		std::string getName( void );
		int getGrade( void );
		// setter
		void setGradeUp( int grade );
		void setGradeDown( int grade );
};

#endif
