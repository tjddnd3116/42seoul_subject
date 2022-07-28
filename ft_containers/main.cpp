// #include "./vector/vector.hpp"
// #include "./stack/stack.hpp"
// #include "./utils/utility.hpp"
#include "./map/map.hpp"
#include <cmath>
#include <exception>
#include <functional>
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
	// std::map<std::string, int, std::greater<std::string> > stdMap;
	// std::map<std::string, int > stdMap;
	std::map<std::string, int>::key_compare kComp;

	if (kComp("1", "2"))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;;

	// stdMap.insert(std::pair<std::string, int>("1", 42));
	// stdMap.insert(std::pair<std::string, int>("6", 42));
	// stdMap.insert(std::pair<std::string, int>("5", 42));
	// for (std::map<std::string, int>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
	// {
	//     std::cout << (*it).first << std::endl;
	//     // std::cout << (*it).second << std::endl;
	// }
	std::cout << "-------stdCont--------" << std::endl;
}

void	ftCont(void)
{
	std::cout << "-------ftCont--------" << std::endl;
	ft::map<std::string, int> myMap;
	ft::pair<ft::map<std::string, int>::iterator, bool> ret;

	std::cout << "insert bb" << std::endl;
	ret = myMap.insert(ft::pair<std::string, int>("bb", 42));
	std::cout << ret.first->first << std::endl;
	std::cout << "insert aa" << std::endl;
	myMap.insert(ft::pair<std::string, int>("aa", 42));
	std::cout << "insert cc" << std::endl;
	myMap.insert(ft::pair<std::string, int>("cc", 42));


	std::cout << "-------ftCont--------" << std::endl;
}

int main(void)
{
	ftCont();
	// stdCont();
	return (0);
}
