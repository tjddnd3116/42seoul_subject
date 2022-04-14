/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:57:07 by soum              #+#    #+#             */
/*   Updated: 2022/04/14 22:32:57 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_hpp
#define DiamondTrap_hpp

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap :public FragTrap, public ScavTrap
{

		private:
			// std::string name;
			// std::string _name;
		public:
			DiamondTrap( void );
			DiamondTrap( std::string name );
			~DiamondTrap();
			void attack( const std::string& target );
			void whoAmI( void );
			void showStatus( void );

};

#endif
