/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:53:56 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 01:05:47 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string.h>

class HumanA {
	private:
		std::string name;
		Weapon &weapon;
	public:
		void attack();
		HumanA(std::string name, Weapon &weapon);
		HumanA();
};

#endif
