/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:06:20 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 04:06:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_hpp
#define AMateria_hpp

#include <iostream>

class ICharacter;

class AMateria
{
		protected:
			std::string _type;

		public:
			// Orthodox Canonical Form
			AMateria( std::string const & type );
			AMateria( const AMateria& amateria );
			AMateria& operator=( const AMateria& amateria );
			virtual ~AMateria();
			// getter
			std::string const & getType() const;
			//member functions
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target) = 0;
};
#endif
