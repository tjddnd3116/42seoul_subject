/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:02:12 by soum              #+#    #+#             */
/*   Updated: 2022/04/03 23:29:34 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie;
	int i;

	zombie = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombie[i].setName(name + std::to_string(i));
		i++;
	}
	return (zombie);
}
