/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:23:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/11 00:02:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap thor("thor");
	ClapTrap loki("loki");


	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	loki.beRepaired(2);
	loki.attack("thor");
	thor.takeDamage(loki.getAttackDamage());
	thor.beRepaired(2);
	thor.beRepaired(2);
	thor.beRepaired(2);
	thor.beRepaired(2);
	thor.beRepaired(2);
	thor.beRepaired(2);
	thor.beRepaired(2);

	return (0);
}
