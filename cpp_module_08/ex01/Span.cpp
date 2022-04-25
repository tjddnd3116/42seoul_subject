/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:44:45 by soum              #+#    #+#             */
/*   Updated: 2022/04/25 15:45:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int arr_len )
{
	_iArr.reserve(arr_len);
}

Span::Span( const Span& span )
{
	*this = span;
}

Span& Span::operator=( const Span& span )
{
	std::vector<int> *tmp = span.getArr();

	_iArr = *tmp;
	delete tmp;
	return (*this);
}

Span::~Span()
{}

std::vector<int>* Span::getArr( void ) const
{
	std::vector<int> *tmp = new std::vector<int>(_iArr);

	return (tmp);
}

void Span::addManyNumbers( void )
{
	std::vector<int>::iterator iter;
	std::srand(time(NULL));

	_iArr.resize(_iArr.capacity());
	for (iter = _iArr.begin(); iter != _iArr.end(); iter++)
		*iter = std::rand();
}

void Span::addNumber( int num )
{
	try {
		if (_iArr.size() == _iArr.capacity())
			throw FullFilled();
		_iArr.push_back(num);
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
		{
			shortest_num = std::min(long(*iter) - long(*(iter - 1)), shortest_num);
			// if (*iter - *(iter - 1) < shortest_num)
			//     shortest_num = long(*iter) - long(*(iter - 1));
		}
		return (shortest_num);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (0);
	}
}

long Span::LongSpan( void ) const
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
		return (0);
	}
}

const char* Span::FullFilled::what() const throw()
{
	return ("exception : array is full");
}

const char* Span::TooShortArr::what() const throw()
{
	return ("exception : array is too short");
}
