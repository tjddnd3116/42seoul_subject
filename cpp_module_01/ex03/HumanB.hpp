/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:56:45 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 00:36:36 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string.h>

class HumanB {
	private:
		Weapon *weapon;
		std::string name;
	public:
		void setWeapon(Weapon& weapon);
		void attack();
		HumanB();
		HumanB(std::string name);
};

#endif
