/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:23:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/11 00:03:23 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap thor("thor");
	ScavTrap loki("loki");

	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	loki.guardGate();

	return (0);
}
