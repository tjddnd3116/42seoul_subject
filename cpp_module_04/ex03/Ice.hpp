/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:20:59 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 22:21:01 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_hpp
#define Ice_hpp

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
		public:
			Ice();
			AMateria* clone() const;
			void use(ICharacter& target);

};
#endif
