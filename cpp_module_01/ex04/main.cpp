/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:10:08 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 19:40:19 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myReplace.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "./replace [filename] [string1] [string2]" << std::endl;
		return (1);
	}
	MyReplace myreplace(argv[1], argv[2], argv[3]);
	if (!myreplace.CheckFile())
	{
		std::cout << "File Error" << std::endl;
		return (1);
	}
	myreplace.DoReplace();
	return (0);
}
