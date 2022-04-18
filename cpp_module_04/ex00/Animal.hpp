/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:02:59 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:02:59 by soum             ###   ########.fr       */
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
			Animal( Animal& animal);
			Animal& operator=( const Animal & animal );
			virtual ~Animal();
			// member functions
			virtual void makeSound( void ) const;
			// getter
			std::string getType( void ) const;
			// setter
			void setType( std::string type );
};
#endif
