/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:50 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:01:34 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	private:
		void showStatus( void );

	public:
		// Orthodox Canonical Form
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& clapTrap );
		ScavTrap & operator=( ScavTrap& clapTrap );
		~ScavTrap();
		// member functions
		void attack( const std::string& target );
		void guardGate( void );
};

#endif
