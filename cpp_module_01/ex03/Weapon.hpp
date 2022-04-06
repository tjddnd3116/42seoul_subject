/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:47:45 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 13:37:03 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

	private:
		std::string _type;

	public:
		const std::string& getType(void);
		void setType(std::string type);
		Weapon(const std::string& type);
};

#endif
