/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:44:45 by soum              #+#    #+#             */
/*   Updated: 2022/05/01 14:48:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n )
{
	_iArr.reserve(n);
}

Span::Span( const Span& span )
{
	*this = span;
}

Span& Span::operator=( const Span& span )
{
	_iArr = span._iArr;
	return (*this);
}

Span::~Span()
{}

void Span::addManyNumbers( void )
{
	std::vector<int>::iterator iter;
	std::srand(time(NULL));

	_iArr.resize(_iArr.capacity());
	for (iter = _iArr.begin(); iter != _iArr.end(); iter++)
		*iter = std::rand();
}

void Span::addNumber( long int num )
{
	try {
		if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
			throw OverflowError();
		if (_iArr.size() == _iArr.capacity())
			throw FullFilled();
		_iArr.push_back(static_cast<int>(num));
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

long Span::shortestSpan( void ) const
{
	try {
		if (_iArr.size() == 0 || _iArr.size() == 1)
			throw TooShortArr();
		long shortest_num;
		std::vector<int> tmp;

		shortest_num = UINT_MAX;
		tmp = _iArr;
		std::sort(tmp.begin(), tmp.end());
		std::vector<int>::iterator iter;
		for (iter = tmp.begin() + 1; iter != tmp.end(); iter++)
			shortest_num = std::min(long(*iter) - long(*(iter - 1)), shortest_num);
		return (shortest_num);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (-1);
	}
}

long Span::longestSpan( void ) const
{
	try {
		if (_iArr.size() == 0 || _iArr.size() == 1)
			throw TooShortArr();
		long longest_num;
		std::vector<int> tmp;

		longest_num = 0;
		tmp = _iArr;
		std::sort(tmp.begin(), tmp.end());
		longest_num = long(*(tmp.end() - 1)) - long(*tmp.begin());
		return (longest_num);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (-1);
	}
}

void Span::printArr( void ) const
{
	std::vector<int>::const_iterator it;

	for (it = _iArr.begin(); it != _iArr.end(); it++)
		std::cout << *it << std::endl;
}

const char* Span::FullFilled::what() const throw()
{
	return ("exception : array is full");
}

const char* Span::TooShortArr::what() const throw()
{
	return ("exception : array is too short");
}

const char* Span::OverflowError::what() const throw()
{
	return ("exception : overflow");
}
