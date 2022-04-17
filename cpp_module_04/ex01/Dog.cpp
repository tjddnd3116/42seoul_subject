#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	_brain = new Brain("cat");
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
	delete []_brain;
}

void Dog::makeSound( void ) const
{
	std::cout << "Arf! Arf!" << std::endl;
}
