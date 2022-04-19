/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:41 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:14:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_hpp
#define WrongCat_hpp

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
		private:
			Brain* _brain;

		public:
			// Orthodox Canonical Form
			WrongCat();
			WrongCat(std::string);
			WrongCat( const WrongCat& wrongcat );
			WrongCat& operator=(const WrongCat& wrongcat );
			~WrongCat();
			// member functions
			void makeSound( void ) const;
			void makeThink( void ) const;
};

#endif
