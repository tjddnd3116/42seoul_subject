/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:32:52 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 20:10:11 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << \
		std::endl << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << \
		std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" \
		<< std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << \
		std::endl << "I’ve been coming for years whereas you started working here since last month." << \
		std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*fp[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	switch (level.at(0)) {
		case 'D':
			(this->*fp[0])();
		case 'I':
			(this->*fp[1])();
		case 'W':
			(this->*fp[2])();
		case 'E':
			(this->*fp[3])();
	}
}
