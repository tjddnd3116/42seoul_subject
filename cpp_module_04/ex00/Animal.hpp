/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:02:59 by soum              #+#    #+#             */
/*   Updated: 2022/05/10 21:25:51 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>

class Animal
{
		protected:
			std::string _type;

		public:
			// Orthodox Canonical Form
			Animal();
			Animal( const Animal& animal);
			Animal& operator=( const Animal & animal );
			~Animal();
			// member functions
			virtual void makeSound( void ) const;
			// getter
			std::string getType( void ) const;
			// setter
			void setType( std::string type );
};
#endif
