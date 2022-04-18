/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:12 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:03:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_hpp
#define WrongAnimal_hpp

#include <iostream>

class WrongAnimal
{
		private:
			std::string _type;

		public:
			// Orthodox Canonical Form
			WrongAnimal();
			WrongAnimal( WrongAnimal& wronganimal );
			WrongAnimal& operator=( const WrongAnimal& wronganimal );
			virtual ~WrongAnimal();
			// member functions
			void makeSound( void ) const;
			// getter
			std::string getType( void ) const;
			// setter
			void setType( std::string type );
};
#endif
