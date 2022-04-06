/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:42:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 12:58:37 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* zom1 = newZombie("zom1");
	Zombie zom2("zom2");

	zom1->announce();
	zom2.announce();
	randomChump("zom3");
	delete zom1;
}
