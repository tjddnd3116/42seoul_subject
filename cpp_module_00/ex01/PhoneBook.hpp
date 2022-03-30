/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:52 by soum              #+#    #+#             */
/*   Updated: 2022/03/30 13:28:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook {
	private:
		contact user[8];
		int	index;
		int fullFilled;

	public:
		void add();
		void search();
		PhoneBook();
};

#endif
