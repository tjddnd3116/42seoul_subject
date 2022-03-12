/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:52 by soum              #+#    #+#             */
/*   Updated: 2022/03/11 13:07:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "info.hpp"

class PhoneBook {
	private:
		info user[8];
		int	index;
		int fullFilled;

	public:
		void add();
		void search();
		PhoneBook();
};

#endif
