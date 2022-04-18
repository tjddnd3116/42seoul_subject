/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:55:06 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:17:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_hpp
#define Cat_hpp

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
		private:
			Brain* _brain;
		public:
			// Orthodox Canonical Form
			Cat();
			Cat(const Cat& cat);
			Cat& operator=(const Cat& cat);
			~Cat();
			// member functions
			void makeSound( void ) const;
};

#endif
