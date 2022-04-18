/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:40:10 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 00:06:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_hpp
#define MateriaSource_hpp


#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
		private:
			AMateria* _materia_slot[4];
		public:
			MateriaSource();
			MateriaSource( MateriaSource& materiasource );
			MateriaSource& operator=( MateriaSource& materiasource );
			~MateriaSource();
			// getter
			AMateria* getMateriaSlot( int idx ) const;
			// setter
			void setNullMateriaSlot( int idx );
			// overriding member functions
			void learnMateria( AMateria* materia );
			AMateria* createMateria( std::string const & type );

};
#endif
