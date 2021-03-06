/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:53:56 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 13:46:25 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string.h>

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		void attack();
		HumanA(std::string name, Weapon &weapon);
		HumanA();
};

#endif
