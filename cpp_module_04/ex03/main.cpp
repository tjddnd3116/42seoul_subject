/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:24:52 by soum              #+#    #+#             */
/*   Updated: 2022/11/01 15:57:52 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	// <subject test>
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");

	me->equip(tmp);
	me->equip(tmp);
	you->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// ICharacter* bob = new Character("bob");
    //
	// me->use(0, *bob);
	// me->use(1, *bob);
    //
	// delete bob;
	// delete me;
	// delete src;

	// <custom test>
	// 1. unequip test
	// ICharacter* test1 = new Character("test1");
    //
	// tmp = src->createMateria("ice");
	// test1->equip(tmp);
	// test1->unequip(0);
	// test1->unequip(1); // can't unequip matera in empty slot
    //
	// delete test1; // check leak!!

	// 2. inventory test
	//     idx error, equip error,
	// ICharacter* test2 = new Character("test2");
	// ICharacter* test3 = new Character("test3");
    //
	// tmp = src->createMateria("ice");
	// test2->equip(tmp);
	// test2->use(1, *test3); // can't use materia in empty slot
	// tmp = src->createMateria("ice");
	// test2->equip(tmp);
	// tmp = src->createMateria("ice");
	// test2->equip(tmp);
	// tmp = src->createMateria("cure");
	// test2->equip(tmp);
	// tmp = src->createMateria("cure");
	// test2->equip(tmp); // can't equip materia
    //
	// delete tmp;
	// delete test2;
	// delete test3;

	// 3. deep copy test
	// ICharacter* test4 = new Character("test4");
    //
	// tmp = src->createMateria("cure");
	// test4->equip(tmp);
	// tmp = src->createMateria("cure");
	// test4->equip(tmp);
	// tmp = src->createMateria("ice");
	// test4->equip(tmp);
    //
	// // tmp = src->createMateria("ice");
	// // test4->equip(tmp);
	// // tmp = src->createMateria("ice");
	// // test4->equip(tmp);
	// // tmp = src->createMateria("ice");
	// // test4->equip(tmp);
    //
	// // ICharacter* test5 = new Character(*test4); // copy constructor
	// // Character test6;
	// // test6 = *(Character *)test4; // copy assignment operator
    //
	// test4->use(0, *test4); // can't use cause test4 matera is deleted
	// // test5->use(0, *test4); // can use ice matera
	// // test6.use(0, *test4); // can't use cause test4 matera is deleted
	//                       // test5 matera have matera of test4
    //
	// delete test4;
	// // delete test5;


	// delete src;

	return (0);
}
