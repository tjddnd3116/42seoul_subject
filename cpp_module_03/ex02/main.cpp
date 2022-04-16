/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:23:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/16 16:09:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap thor("thor");
	FragTrap loki("loki");

	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	thor.attack("loki");
	loki.takeDamage(thor.getAttackDamage());
	loki.beRepaired(10);
	thor.highFivesGuys();

	return (0);
}
