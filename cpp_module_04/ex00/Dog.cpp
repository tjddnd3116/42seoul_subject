#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
	:Animal()
{
	setType("Dog");
	std::cout << getType() << " created" << std::endl;
}

Dog::Dog(const Dog& dog)
	:Animal()
{
	*this = dog;
}

Dog& Dog::operator=(const Dog &dog)
{
	this->setType(dog.getType());
	return (*this);
}

Dog::~Dog()
{
	std::cout << getType() << " deleted" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Arf! Arf!" << std::endl;
}
