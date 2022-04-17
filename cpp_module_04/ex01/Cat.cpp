#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
	:Animal()
{
	_brain = new Brain("dog");
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
	(*this->_brain) = (*cat._brain);
	this->setType(cat.getType());
	return (*this);
}

Cat::~Cat()
{
	std::cout << getType() << " deleted" << std::endl;
	delete _brain;
}

void Cat::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}
