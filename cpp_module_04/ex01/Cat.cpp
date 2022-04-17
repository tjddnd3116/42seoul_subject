#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	setType("Cat");
	std::cout << getType() << " created" << std::endl;
}

Cat::Cat(const Cat& cat)
	:Animal()
{
	*this = cat;
}


Cat& Cat::operator=(const Cat& cat)
{
	this->setType(cat.getType());
	return (*this);
}

Cat::~Cat()
{
	std::cout << getType() << " deleted" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}
