/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:00:38 by soum              #+#    #+#             */
/*   Updated: 2022/05/10 21:26:13 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "<Animal Class create>" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	// delete j;
	// delete i;
	// delete meta;


	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// j->makeSound(); //will output the cat sound!
	// i->makeSound();
	// meta->makeSound();
    //
	// std::cout << "<WrongAnimal Class create>" << std::endl;
	// const WrongAnimal* wronganimal = new WrongAnimal();
	// const WrongAnimal* wrongcat = new WrongCat();
    //
	// wronganimal->makeSound();
	// wrongcat->makeSound();
    //
	// std::cout << "<Animal delete>" << std::endl;
	// delete meta;
	// delete j;
	// delete i;
    //
	// std::cout << "<WrongAnimal delete>" << std::endl;
	// delete wronganimal;
	// delete wrongcat;

	return (0);
}
