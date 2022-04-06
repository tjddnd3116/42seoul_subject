/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:40:51 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 13:25:02 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		void announce(void);
		void setName( std::string name );
		Zombie( std::string name );
		Zombie();
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif
