/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:50 by soum              #+#    #+#             */
/*   Updated: 2022/04/15 12:47:28 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	private:
		void showStatus( void );

	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap();
		void attack( const std::string& target );
		void guardGate( void );
};

#endif
