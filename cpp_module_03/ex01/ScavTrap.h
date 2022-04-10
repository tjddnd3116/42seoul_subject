/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:50 by soum              #+#    #+#             */
/*   Updated: 2022/04/10 22:23:34 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define	SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {

	private:
		void showStatus( void );

	public:
		ScavTrap( std::string name );
		~ScavTrap();
		void attack( const std::string& target );
		void guardGate( void );
};

#endif
