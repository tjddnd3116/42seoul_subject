/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:06 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 00:16:26 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_hpp
#define Dog_hpp

#include "Animal.hpp"

class Dog : public Animal
{
		private:

		public:
			// Orthodox Canonical Form
			Dog();
			Dog( const Dog& dog );
			Dog& operator=( const Dog& dog );
			~Dog();
			// member functions
			void makeSound( void ) const;
};
#endif
