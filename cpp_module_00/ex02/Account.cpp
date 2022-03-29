/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:07:57 by soum              #+#    #+#             */
/*   Updated: 2022/03/29 16:24:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(void)
{
}

Account::Account(int deposit)
{
}

void	Account::_displayTimestamp(void)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	if (t->tm_sec < 10)
	{
		std::cout << "[" << t->tm_year + 1900 << t->tm_mon + 1 << t->tm_mday
		<< "_" << t->tm_hour << t->tm_min << "0" << t->tm_sec << "] ";
	}
	else
	{
		std::cout << "[" << t->tm_year + 1900 << t->tm_mon + 1 << t->tm_mday
		<< "_" << t->tm_hour << t->tm_min << t->tm_sec << "] ";
	}
}
int	Account::getNbAccounts(void)
{
	return (0);
}

int Account::getTotalAmount(void)
{
	return (0);
}

int Account::getNbDeposits(void)
{
	return (0);
}

int Account::getNbWithdrawals(void)
{
	return (0);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

}

void	Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{
	return(true);
}

int Account::checkAmount(void) const
{
	return (0);
}

void Account::displayStatus(void) const
{

}

Account::~Account()
{

}
