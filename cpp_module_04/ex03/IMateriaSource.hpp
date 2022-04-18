/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:07:08 by soum              #+#    #+#             */
/*   Updated: 2022/04/19 00:01:22 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource_hpp
#define IMateriaSource_hpp

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
		public:
			virtual ~IMateriaSource() {}
			virtual void learnMateria( AMateria* ) = 0;
			virtual AMateria* createMateria( std::string const & type ) = 0;
};

#endif
