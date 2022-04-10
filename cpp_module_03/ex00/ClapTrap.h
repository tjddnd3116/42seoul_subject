/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:45:03 by soum              #+#    #+#             */
/*   Updated: 2022/04/10 15:59:00 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

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
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap& clapTrap );
		ClapTrap & operator=( ClapTrap& clapTrap );
		~ClapTrap();
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		unsigned int getAttackDamage( void );
};

#endif
