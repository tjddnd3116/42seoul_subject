/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:01:11 by soum              #+#    #+#             */
/*   Updated: 2022/04/03 23:31:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int num;
	int i;
	Zombie* zombie;

	num = 5;
	zombie = zombieHorde(num, "zom");
	i = 0;
	while (i < 5)
	{
		zombie[i].announce();
		i++;
	}
	delete [] zombie;
}
