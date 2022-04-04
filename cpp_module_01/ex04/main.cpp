/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:10:08 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 18:34:49 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "./replace [filename] [string1] [string2]" << std::endl;
		return (1);
	}
	else
	{
		std::string filename;
		std::string string1;
		std::string string2;
		std::ifstream readFile;
		std::ofstream writeFile;
		char buf[1024];

		string1 = argv[2];
		string2 = argv[3];
		readFile.open(argv[1]);
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile.getline(buf, 1024);
				std::cout << buf << '\n';
			}
			readFile.close();
		}
		else
		{
			std::cout << "check file name!" << std::endl;
			return (1);
		}
	}
	return (0);
}
