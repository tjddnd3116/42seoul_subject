/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:45:03 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:10:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

class ClapTrap {

	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		void showStatus( void );

	public:
		// Orthodox Canonical Form
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& clapTrap );
		ClapTrap & operator=( ClapTrap& clapTrap );
		~ClapTrap();
		// member functions
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		//getter
		unsigned int getAttackDamage( void ) const;
};

#endif
