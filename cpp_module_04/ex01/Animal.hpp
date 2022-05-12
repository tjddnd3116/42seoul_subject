/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:22 by soum              #+#    #+#             */
/*   Updated: 2022/05/10 21:25:04 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>

class Animal
{
		private:
			std::string _type;

		public:
			// Orthodox Canonical Form
			Animal();
			Animal( const Animal& animal);
			Animal& operator=( const Animal & animal );
			~Animal();
			// member functions
			void makeSound( void ) const;
			// getter
			std::string getType( void ) const;
			// setter
			void setType( std::string type );
};
#endif
