/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:36:48 by soum              #+#    #+#             */
/*   Updated: 2022/04/10 22:40:23 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
		private:
			void showStatus( void );

		public:
			FragTrap( std::string name );
			~FragTrap();
			void attack( const std::string& target );
			void highFivesGuys( void );

};

#endif
