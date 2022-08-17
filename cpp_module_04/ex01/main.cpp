/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:00:38 by soum              #+#    #+#             */
/*   Updated: 2022/08/17 21:59:43 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// <subject test>
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	// <custom test1>
	// ----------------------------------------------------------------------
	// create and fill an array of Animal objects							|
	// Half of it will be Dog objects and the ther half will be Cat objects	|
	// end of program array and delete every Animal							|
	// munt delete directly dogs and cats as Animal							|
	// ----------------------------------------------------------------------

	// const Animal *(animalArr[6]);
	// for (int i = 0; i < 6; i++)
	// {
	//     animalArr[i] = new Dog();
	//     i++;
	//     animalArr[i] = new Cat();
	// }
	// for (int i = 0; i < 6; i++)
	//     animalArr[i]->makeSound();
	// for (int i = 0; i < 6; i++)
	//     delete animalArr[i];

	// <custom test2>
	// -----------------------------------
	// test that copies are deep copies!  |
	// ------------------------------------

	// deepcopy
    //
	// Cat *j = new Cat("4242");
	// Cat i = *j;
    //
	// j->makeSound();
	// i.makeSound();
    //
	// j->makeThink();
	// i.makeThink();
    //
	// delete j;
    //
	// shallow copy
	// ****Do Not Do This!!!****

	// WrongCat *jj = new WrongCat();
	WrongCat ii;
	// std::cout << "ff" << std::endl;

	// ii = *jj;
	// jj->makeSound();
	// ii.makeSound();

	// delete jj;

	return (0);
}
