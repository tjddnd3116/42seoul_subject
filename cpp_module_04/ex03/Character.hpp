/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:56:54 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 04:56:12 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_hpp
#define Character_hpp


#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
		private:
			std::string _name;
			AMateria* _materia_slot[4];
			AMateria* _materia_trash[10];

		public:
			// Orthodox
			Character();
			Character( std::string name );
			Character( Character& character );
			Character( ICharacter& character );
			Character& operator=( Character& character );
			~Character();
			// getter
			std::string const & getName( void ) const;
			AMateria* getMateriaSlot( int idx ) const;
			// setter
			void setNullMateriaSlot( int idx );
			// overriding member functions
			void equip( AMateria* m );
			void unequip( int idx );
			void use( int idx, ICharacter& target );
			// member functions
			int materiaToTrash( AMateria* m );
};
#endif
