#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal()
{
	setType("WrongCat");
	std::cout << "\033[31m" << getType() << " created" << "\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
	:WrongAnimal()
{
	*this = wrongcat; 
}

WrongCat& WrongCat::operator=(const WrongCat &wrongcat)
{
	this->setType(wrongcat.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "\033[31m" << getType() << " deleted" << "\033[0m" << std::endl;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "\033[31m" << "W...W" << "\033[0m" << std::endl;
}
