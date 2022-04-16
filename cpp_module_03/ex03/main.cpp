/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:23:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 17:24:01 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::string s1 = "Clyde";
	std::string s2 = "Scarlet";
	std::string s3 = "Fred";
	std::string s4 = "Diego";

	// Constructors
	DiamondTrap	diamondtrap(s4);

	// Repairs
	diamondtrap.takeDamage(14);
	diamondtrap.beRepaired(18);

	// New class attack until exhaustion
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);

	diamondtrap.guardGate();
	diamondtrap.attack(s2);

	// New class personal method call
	diamondtrap.highFivesGuys();

	diamondtrap.whoAmI();
	// Repair over max hp
	diamondtrap.beRepaired(18);

	// Take damage
	diamondtrap.takeDamage(50);

	// Die
	diamondtrap.takeDamage(50);

	// Do something after dying
	diamondtrap.beRepaired(20);
	diamondtrap.attack(s2);

	return (0);
	// DiamondTrap loki("loki");
	// DiamondTrap thor("thor");
    //
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.attack("loki");
	// loki.takeDamage(thor.getAttackDamage());
	// thor.guardGate();
	// thor.highFivesGuys();
	// loki.whoAmI();
	// thor.whoAmI();
    //
	// return (0);
}
