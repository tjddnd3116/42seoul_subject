/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:26:32 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 22:42:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myReplace.hpp"
#include <string>

MyReplace::MyReplace(std::string filename, std::string string1, std::string string2)
{
	_readFile.open(filename);
	_writeFile.open(filename.append(".replace"));
	_string1 = string1;
	_string2 = string2;
}

bool MyReplace::CheckFile()
{
	if (_readFile.fail() || _writeFile.fail())
		return (false);
	else
		return (true);
}

void MyReplace::DoReplace()
{
	char buf[1024];
	std::string bufToString;
	// size_t idx;

	// while(!_readFile.eof())
	// {
	//
		// std::cout << (_readFile.rdstate() & _readFile.failbit) << std::endl;
		_readFile.getline(buf, 1024);
		bufToString = buf; //bufToString = ddd42ddd42d
		std::cout << bufToString << std::endl;
		// bufToString.clear();
		_readFile.clear();
		// bufToString.clear();
		// std::cout << (_readFile.rdstate() & _readFile.failbit) << std::endl;
		// std::cout << _readFile.failbit << std::endl;
		_readFile.getline(buf,10);
		bufToString = buf;
		std::cout << buf << std::endl;
		// while(bufToString.size())
		// {
		//     idx = bufToString.find(_string1); // idx = 3
		//     std::cout << idx << std::endl;
		//     if (idx != bufToString.npos)
		//     {
		//         _writeFile.write(bufToString.c_str(), idx);
		//         _writeFile.write(_string2.c_str(), _string2.size());
		//         bufToString = (buf + idx + _string1.size());
		//     }
		//     std::cout << "bufTostring : "<< bufToString << std::endl;
		//     idx = bufToString.find(_string1);
		//     std::cout << idx  << std::endl; */
		//     else
		//     {
		//         _writeFile.write(bufToString.c_str(), bufToString.size());
		//         bufToString = "";
		//     }
		// }
		// _writeFile.write("\n", 1);
	// }
}

MyReplace::~MyReplace()
{
	_readFile.close();
	_writeFile.close();
}
