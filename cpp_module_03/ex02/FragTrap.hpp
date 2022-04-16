/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:36:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:13:23 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
		private:
			void showStatus( void );

		public:
			// Orthodox Canonical Form
			FragTrap();
			FragTrap( std::string name );
			FragTrap( const FragTrap& fragTrap );
			FragTrap & operator=(FragTrap& fragTrap);
			~FragTrap();
			// member functions
			void attack( const std::string& target );
			void highFivesGuys( void );

};

#endif
