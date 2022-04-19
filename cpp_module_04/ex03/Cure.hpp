/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:13:54 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:38:28 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_hpp
#define Cure_hpp

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
		public:
			// Orthodox Canonical Form
			Cure();
			Cure( const Cure& cure );
			Cure& operator=( const Cure& cure );
			~Cure();
			// overriding member functions
			AMateria* clone() const;
			void use(ICharacter& target);
};
#endif
