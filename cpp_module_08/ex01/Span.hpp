/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:44:40 by soum              #+#    #+#             */
/*   Updated: 2022/05/01 14:37:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_hpp
#define Span_hpp

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
		private:
			std::vector<int> _iArr;

		public:
			// Orthodox Canonical Form
			Span( unsigned int n );
			Span( const Span& span );
			Span& operator=( const Span& span );
			~Span();
			// member functions
			void addManyNumbers( void );
			void addNumber( long int num );
			long shortestSpan( void ) const;
			long longestSpan( void ) const;
			void printArr( void ) const;
			// exception class inheritance
			class FullFilled : public std::exception {
				const char* what() const throw();
			};
			class TooShortArr : public std::exception {
				const char* what() const throw();
			};
			class OverflowError : public std::exception {
				const char* what() const throw();
			};
};
#endif //Span_hpp
