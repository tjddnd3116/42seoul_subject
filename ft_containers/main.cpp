#include "./vector/vector.hpp"
#include "./utils/utility.hpp"
#include <cmath>
#include <exception>
#include <iterator>
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>
#include <map>

class myClass
{
	private:
		std::string _name;
	public:
		myClass()
		{
			std::cout << "constructor call" << std::endl;
			_name = "no_name";
		}
		myClass(const myClass& op)
		{
			std::cout << "copy constructor call" << std::endl;
			_name = op._name;
		}
		myClass(std::string& newName)
		{
			std::cout << "constructor call" << std::endl;
			_name = newName;
		}
		~myClass()
		{
			std::cout << "destructor call" << std::endl;
		}
		myClass& operator=(const myClass& rhs)
		{
			std::cout << "copy assignment operator call" << std::endl;
			_name = rhs._name;
			return (*this);
		}
};

void	stdCont(void)
{
	std::cout << "-------stdCont--------" << std::endl;
	std::cout << "-------stdCont--------" << std::endl;
}

void	ftCont(void)
{
	std::cout << "-------ftCont--------" << std::endl;
	ft::pair<std::string, int> myPair1;
	ft::pair<std::string, int> myPair2("ftCont", 1);
	ft::pair<std::string, int> myPair3(myPair2);

	myPair1.first = "abcd";
	myPair1.second = 42;
	std::cout << "myPair 1 : "<< myPair1.first << " " << myPair1.second << std::endl;
	std::cout << "myPair 2 : "<< myPair2.first << " " << myPair2.second << std::endl;
	std::cout << "myPair 3 : "<< myPair3.first << " " << myPair3.second << std::endl;

	std::cout << "-------ftCont--------" << std::endl;
}

int main(void)
{
	ftCont();
	// stdCont();
	return (0);
}
