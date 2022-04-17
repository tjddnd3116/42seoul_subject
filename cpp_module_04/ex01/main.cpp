/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:00:38 by soum              #+#    #+#             */
/*   Updated: 2022/04/17 22:38:29 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// const Animal*j = new Cat();

	// j->makeSound();
	// delete j;

	Cat *cat = new Cat;
	Cat cat2;

	cat2 = *cat;


	delete cat;
	return (0);
}
