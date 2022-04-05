/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:31:41 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 20:14:35 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int argc, char **argv)
{
	Harl harl;
	std::string cmd;

	if (argc != 2)
		return (1);
	cmd = argv[1];
	if (cmd == "DEBUG")
		harl.complain("DEBUG");
	else if (cmd == "INFO")
		harl.complain("INFO");
	else if (cmd == "WARNING")
		harl.complain("WARNING");
	else if (cmd == "ERROR")
		harl.complain("ERROR");
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}
