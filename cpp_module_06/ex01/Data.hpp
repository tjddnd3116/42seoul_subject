/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:25:31 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 14:58:10 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Data_hpp
#define Data_hpp

#include <sys/_types/_uintptr_t.h>
#include <iostream>

struct Data
{
	int _data;
};

uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );

#endif
