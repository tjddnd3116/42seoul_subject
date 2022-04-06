/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:26:32 by soum              #+#    #+#             */
/*   Updated: 2022/04/06 17:18:54 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyReplace.hpp"

MyReplace::MyReplace(std::string filename, std::string string1, std::string string2)
{
	_readFile.open(filename);
	if (_readFile.is_open())
		_writeFile.open(filename.append(".replace"));
	_string1 = string1;
	_string2 = string2;
}

bool MyReplace::CheckFile()
{
	if (_readFile.fail() || _writeFile.fail())
		return (false);
	else if (_readFile.is_open() && _writeFile.is_open())
		return (true);
	return (false);
}

void MyReplace::DoReplace()
{
	char buf[1024];
	std::string bufToString;
	size_t idx;

	while(!_readFile.eof())
	{
		_readFile.getline(buf, 1024, '\n');
		bufToString = buf;
		idx = 0;
		while(true)
		{
			idx = bufToString.find(_string1);
			if (idx != bufToString.npos)
			{
				_writeFile.write(bufToString.c_str(), idx);
				_writeFile.write(_string2.c_str(), _string2.size());
				bufToString = (bufToString.c_str() + idx + _string1.size());
			}
			else
			{
				_writeFile.write(bufToString.c_str(), bufToString.size());
				break;
			}
		}
		if (_readFile.fail() && !_readFile.eof())
		{
			_readFile.clear();
			continue;
		}
		if (!_readFile.eof())
			_writeFile.write("\n", 1);
	}
}

MyReplace::~MyReplace()
{
	if (_readFile.is_open())
		_readFile.close();
	if (_writeFile.is_open())
		_writeFile.close();
}
