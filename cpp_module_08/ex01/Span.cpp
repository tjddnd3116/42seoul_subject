/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:44:45 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 22:53:56 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int arr_len )
{
	_iArr.resize(arr_len);
}

Span::Span( const Span& span )
{
	*this = span;
}

Span& Span::operator=( const Span& span )
{
	return (*this);
}

Span::~Span()
{

}

void Span::addNumber( int num )
{

	_iArr.push_back(num);
}

int Span::shortestSpan( void ) const
{

}

int Span::LongSpan( void ) const
{

}
