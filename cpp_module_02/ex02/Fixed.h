/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:02:12 by soum              #+#    #+#             */
/*   Updated: 2022/04/08 19:53:39 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	private:
		int _fixedPointNum;
		static const int _bits;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fixed);
		Fixed & operator=(const Fixed& fixed);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed& fixed);
		bool operator<(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);

		float operator+(const Fixed& fixed);
		float operator-(const Fixed& fixed);
		float operator*(const Fixed& fixed);
		float operator/(const Fixed& fixed);

		Fixed& operator++(); // 전위
		Fixed& operator++(int); //후위
		Fixed& operator--();
		Fixed& operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
