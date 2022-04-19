/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:20:59 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:38:53 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_hpp
#define Ice_hpp

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
		public:
			// Orthodox Canonical Form
			Ice();
			Ice( const Ice& ice );
			Ice& operator=( const Ice& ice );
			~Ice();
			// overriding member functions
			AMateria* clone() const;
			void use(ICharacter& target);

};
#endif
