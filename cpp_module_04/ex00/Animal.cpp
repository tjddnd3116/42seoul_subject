#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << _type << " created" << std::endl;
}

Animal::Animal(Animal& animal)
{
	*this = animal;
}

Animal& Animal::operator=(Animal & animal)
{
	_type = animal.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << _type << " deleted" << std::endl;
}

void Animal::makeSound( void ) const
{
	std::cout << "  " << std::endl;
}

std::string Animal::getType( void ) const
{
	return (_type);
}

void Animal::setType( std::string type )
{
	_type = type;
}

