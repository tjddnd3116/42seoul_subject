/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:40:10 by soum              #+#    #+#             */
/*   Updated: 2022/04/20 02:57:57 by soum             ###   ########.fr       */
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
			// Orthodox Canonical Form
			MateriaSource();
			MateriaSource( const MateriaSource& materiasource );
			MateriaSource& operator=( const MateriaSource& materiasource );
			~MateriaSource();
			// getter
			AMateria* getMateriaSlot( int idx ) const;
			// overriding member functions
			void learnMateria( AMateria* materia );
			AMateria* createMateria( std::string const & type );

};
#endif
