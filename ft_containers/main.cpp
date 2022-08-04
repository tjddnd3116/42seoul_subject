#include "./vector/vector.hpp"
#include "./stack/stack.hpp"
#include "./utils/utility.hpp"
#include "./map/map.hpp"
#include <cmath>
#include <cstdlib>
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
	std::map<int, int > stdMap;
	std::map<int, int>::const_iterator constMapIt;
	std::map<int, int>::iterator MapIt;
	// std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> ret;

	stdMap.insert(std::make_pair(100, 2));
	stdMap.insert(std::pair<int, int>(10, 2));
	stdMap.insert(std::pair<int, int>(15, 1));
	stdMap.insert(std::pair<int, int>(1, 5));
	stdMap.insert(std::pair<int, int>(3, 4));
	stdMap.insert(std::pair<int, int>(5, 3));
	constMapIt = stdMap.end();
	MapIt = stdMap.begin();
	if (constMapIt == MapIt)
	{

	}
	--constMapIt;
	std::cout << constMapIt->first << std::endl;
	std::cout << constMapIt->second << std::endl;
	// mapIt = stdMap.upper_bound(14);
	// ret = stdMap.equal_range(15);
	// std::cout << ret.first->first << std::endl;
	// std::cout << ret.first->second << std::endl;
	// std::cout << "-------------" << std::endl;
	// std::cout << (--ret.second)->first << std::endl;
	// std::cout << (--ret.second)->second << std::endl;
	std::cout << "-------stdCont--------" << std::endl;
}

void	ftCont(void)
{
	std::cout << "-------ftCont--------" << std::endl;
	ft::map<int, int> myMap;
	myMap.insert(ft::pair<int, int>(17, 42));
	myMap.insert(ft::pair<int, int>(15, 42));
	myMap.insert(ft::pair<int, int>(10, 42));
	myMap.insert(ft::pair<int, int>(13, 42));
	myMap.insert(ft::pair<int, int>(16, 42));
	myMap.insert(ft::pair<int, int>(25, 42));
	myMap.insert(ft::pair<int, int>(18, 42));
	myMap.insert(ft::pair<int, int>(19, 42));
	myMap.insert(ft::pair<int, int>(40, 42));
	myMap.insert(ft::pair<int, int>(1, 42));
	myMap.insert(ft::pair<int, int>(42, 42));
	myMap.insert(ft::pair<int, int>(7, 42));
	myMap.insert(ft::pair<int, int>(3, 42));
	myMap.insert(ft::pair<int, int>(2, 42));
	myMap.insert(ft::pair<int, int>(5, 42));
	myMap.insert(ft::pair<int, int>(28, 42));
	myMap.insert(ft::pair<int, int>(30, 42));
	myMap.insert(ft::pair<int, int>(34, 42));
	myMap.insert(ft::pair<int, int>(44, 42));
	std::cout << "-----------------" << std::endl;
	myMap.erase(16);
	// myMap.erase(10);
	// myMap.erase(13);
	// myMap.erase(25);
	// myMap.erase(18);
	// myMap.erase(19);
	// myMap.erase(40);
	// myMap.erase(1);
	// myMap.erase(42);
	// myMap.erase(7);
	// myMap.erase(3);
	// myMap.erase(2);
	// myMap.erase(5);
	// myMap.erase(28);
	// myMap.erase(30);
	// myMap.erase(34);
	// myMap.erase(44);
	std::cout << "-------ftCont--------" << std::endl;
}

int main(void)
{
	ftCont();
	// stdCont();
	// system("leaks a.out");
	return (0);
}
