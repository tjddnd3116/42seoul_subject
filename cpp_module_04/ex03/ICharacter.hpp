/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:50:31 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 18:27:16 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter_hpp
#define ICharacter_hpp

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
		public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
};
#endif
