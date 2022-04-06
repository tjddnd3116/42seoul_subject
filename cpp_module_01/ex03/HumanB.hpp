/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:56:45 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 13:47:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string.h>

class HumanB {
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		void setWeapon(Weapon& weapon);
		void attack();
		HumanB();
		HumanB(std::string name);
};

#endif
