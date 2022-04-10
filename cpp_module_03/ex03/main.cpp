/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:23:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/11 00:06:07 by soum             ###   ########.fr       */
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
	thor.highFivesGuys();

	return (0);
}
