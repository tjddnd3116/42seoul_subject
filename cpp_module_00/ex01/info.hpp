/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:36:03 by soum              #+#    #+#             */
/*   Updated: 2022/03/12 18:42:18 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>
#include <string>
#include <iomanip>

class info {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void fillInfo();
		void showInfo();
		void reSizeInfo();
};

#endif
