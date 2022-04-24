/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:25:31 by soum              #+#    #+#             */
/*   Updated: 2022/04/24 15:00:45 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t result;

	result = reinterpret_cast<uintptr_t>(ptr);
	return (result);
}

Data* deserialize( uintptr_t raw )
{
	Data *result;

	result = reinterpret_cast<Data*>(raw);
	return (result);
}
