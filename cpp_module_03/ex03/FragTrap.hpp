/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:36:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:01:11 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
		private:
			void showStatus( void );

		public:
			// Orthodox Canonical Form
			FragTrap();
			FragTrap( std::string name );
			FragTrap( const FragTrap& fragTrap );
			FragTrap & operator=(FragTrap& fragTrap );
			~FragTrap();
			// member funtions
			void attack( const std::string& target );
			void highFivesGuys( void );
};

#endif
