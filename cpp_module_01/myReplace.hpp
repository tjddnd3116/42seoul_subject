/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:18:12 by soum              #+#    #+#             */
/*   Updated: 2022/04/04 19:36:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYREPLACE_HPP
#define MYREPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class MyReplace {

	private:
		std::string _string1;
		std::string _string2;
		std::ifstream _readFile;
		std::ofstream _writeFile;

public:
		MyReplace(std::string filename, std::string string1, std::string string2);
		bool CheckFile();
		void DoReplace();
		~MyReplace();
};

#endif
