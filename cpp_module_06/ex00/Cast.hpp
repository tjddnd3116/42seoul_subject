/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:56:33 by soum              #+#    #+#             */
/*   Updated: 2022/04/21 23:22:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cast_hpp
#define Cast_hpp

#include <exception>
#include <iostream>
#include <ostream>

class Cast
{
		private:
			// member variable
			std::string _numStr;
			std::string _type;
			char _cval;
			int _ival;
			float _fval;
			double _dval;
			int _cvalOverFlowFlag;
			int _ivalOverFlowFlag;
			int _fvalOverFlowFlag;
			// member functions
			void checkNum( std::string num_str );
			void convert ( void );
			void casting ( char val );
			void casting ( int val );
			void casting ( float val );
			void casting ( double val );
			void overflowCheck( void );
		public:
			Cast( std::string num_str );
			Cast( const Cast& );
			Cast& operator=( const Cast& cast );
			~Cast();
			// getter
			std::string getType( void ) const;
			std::string getNumStr( void ) const;
			int getFlags( int idx ) const;
			char getCval( void ) const;
			int getIval( void ) const;
			float getFval( void ) const;
			double getDval( void ) const;
			// exception class
			class MyException : public std::exception{
					std::string _errMsg;
				public:
					MyException( const std::string err_msg );
					~MyException() throw();
					const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream &os, const Cast& cast);

#endif
