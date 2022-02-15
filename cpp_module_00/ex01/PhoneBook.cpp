/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:31:47 by soum              #+#    #+#             */
/*   Updated: 2022/02/14 13:34:44 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::cout << "first name : ";
	std::getline(std::cin, first_name);
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	std::cout << "nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "phone number : ";
	std::getline(std::cin, phone_number);
	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret);

}

void	PhoneBook::search()
{
	std::cout << first_name;
	std::cout << last_name;
	std::cout << nickname;
	std::cout << phone_number;
	std::cout << darkest_secret << std::endl;
}
