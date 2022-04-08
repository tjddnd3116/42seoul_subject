/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:02:12 by soum              #+#    #+#             */
/*   Updated: 2022/04/07 18:42:41 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>

class Fixed {
	private:
		int _fixedPointNum;
		static const int _bits;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed & operator=(const Fixed& fixed);
		~Fixed();
		int getRawBits( void ) const ;
		void setRawBits( int const raw );
};

#endif
