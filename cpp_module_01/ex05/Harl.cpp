/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:32:52 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 19:47:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

void Harl::debug(void)
{
	std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\"" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\"" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\"" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string firstCharLevel;
	void (Harl::*fp[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	firstCharLevel = "DIWE";
	(this->*fp[firstCharLevel.find(level.at(0))])();
}
