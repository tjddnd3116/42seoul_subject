/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:15 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 00:18:38 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_hpp
#define WrongCat_hpp

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
		private:

		public:
			// Orthodox Canonical Form
			WrongCat();
			WrongCat( const WrongCat& wrongcat );
			WrongCat& operator=( const WrongCat& wrongcat );
			~WrongCat();
			// member functions
			void makeSound( void ) const;
};

#endif
