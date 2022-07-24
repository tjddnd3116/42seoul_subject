#include "./vector/vector.hpp"
#include "./stack/stack.hpp"
#include "./utils/utility.hpp"
#include "./map/map.hpp"
#include <cmath>
#include <exception>
#include <iterator>
#include <algorithm>
#include <memory>
#include <string>
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
	std::map<std::string, int> stdMap;

	std::cout << "-------stdCont--------" << std::endl;
}

void	ftCont(void)
{
	std::cout << "-------ftCont--------" << std::endl;
	ft::map<std::string, int> myMap;
	myMap.insert(ft::pair<std::string, int>("aa", 42));
	std::cout << "-------ftCont--------" << std::endl;
}

int main(void)
{
	// ftCont();
	stdCont();
	return (0);
}
