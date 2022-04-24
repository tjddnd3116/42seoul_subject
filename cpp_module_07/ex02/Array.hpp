/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:00:56 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 22:00:17 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int _arrLen;
		T* _arr;
	public:
		// Orthodox Canonical Form
		Array () {
			_arrLen = 0;
			_arr = new T[_arrLen]();
		}
		Array( unsigned int arr_len ){
			_arrLen = arr_len;
			_arr = new T[arr_len]();
		}
		Array( const Array& array ) {
			_arrLen = array.size();
			_arr = new T[_arrLen]();
			*this = array;
		}
		Array& operator=( const Array& array ){
			delete []_arr;
			_arr = NULL;
			_arrLen = array.size();
			_arr = new T[_arrLen]();
			for (unsigned int i = 0; i < _arrLen; i++)
				_arr[i] = array.getArrVal(i);
			return (*this);
		}
		~Array() {
			delete [] _arr;
			_arr = NULL;
		}
		// exception class inheritance
		class OutOfRange : public std::exception{
			const char* what() const throw(){
				return "out of range";
			} };
		// operator overloading
		T& operator[] ( int idx ) {
			if (idx < 0 || idx >= int(_arrLen))
				throw OutOfRange();
			return (_arr[idx]);
		}
		// member functions
		unsigned int size( void ) const {
			return (_arrLen);
		}
		// getter
		const T getArrVal( int idx ) const {
			return (_arr[idx]);
		}
};
