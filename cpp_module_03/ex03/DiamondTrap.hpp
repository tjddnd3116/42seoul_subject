/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:57:07 by soum              #+#    #+#             */
/*   Updated: 2022/04/15 12:48:09 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_hpp
#define DiamondTrap_hpp

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :public FragTrap, public ScavTrap
{

		private:
			std::string _name;
		public:
			DiamondTrap( void );
			DiamondTrap( std::string name );
			~DiamondTrap();
			void attack( const std::string& target );
			void whoAmI( void );
			void showStatus( void );

};

#endif
