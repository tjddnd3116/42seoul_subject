/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:44:40 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 22:53:02 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_hpp
#define Span_hpp


#include <vector>
class Span
{
		private:
			std::vector<int> _iArr;

		public:
			// Orthodox Canonical Form
			Span( unsigned int arr_len );
			Span( const Span& span );
			Span& operator=( const Span& span );
			~Span();
			// member functions
			void addNumber( int num );
			int shortestSpan( void ) const;
			int LongSpan( void ) const;
};
#endif //Span_hpp
