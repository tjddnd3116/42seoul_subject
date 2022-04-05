/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:10:08 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 20:55:59 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyReplace.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "./replace \"filename\" \"s1\" \"s2\"" << std::endl;
		return (1);
	}
	MyReplace myreplace(argv[1], argv[2], argv[3]);
	if (!myreplace.CheckFile())
	{
		std::cout << "File Error " <<std::endl;
		return (1);
	}
	myreplace.DoReplace();
	std::cout << argv[1] << " replace finish!\ncheck " << argv[1] << ".replace" << std::endl;
	return (0);
}
