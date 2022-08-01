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
	std::map<std::string, int > stdMap;
	std::map<std::string, int>::iterator mapIt;

	// stdMap.insert(std::pair<std::string, int>("1", 42));
	mapIt = stdMap.find("2");
	mapIt--;
	std::cout << mapIt->first << std::endl;
	std::cout << mapIt->second << std::endl;
	std::cout << "-------stdCont--------" << std::endl;
}

void	ftCont(void)
{
	std::cout << "-------ftCont--------" << std::endl;
	ft::map<int, int> myMap;
	ft::map<int, int>::iterator mapIt;
	ft::pair<ft::map<int, int>::iterator, bool> ret;
    //
	// std::cout << myMap.max_size() << std::endl;
	std::cout << "-----insert 8-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(8, 42));
	// // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 18-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(18, 42));
	// // // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 5-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(5, 42));
	// // // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 15-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(15, 42));
	// // // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 17-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(17, 42));
	// // // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 25-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(25, 42));
	// // // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 40-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(40, 42));
	// // // std::cout << ret.first->first << std::endl;
	std::cout << "-----insert 80-----" << std::endl;
	ret = myMap.insert(ft::pair<int, int>(80, 42));
	std::cout << myMap.count(81) << std::endl;
	// // std::cout << ret.first->first << std::endl;
	// // std::cout << "-----insert 80-----" << std::endl;
	// // ret = myMap.insert(ft::pair<int, int>(80, 42));
	// // std::cout << ret.first->first << std::endl;
	// // std::cout << ret.second << std::endl;
	// std::cout << myMap.size() << std::endl;
	std::cout << "-------ftCont--------" << std::endl;
}

int main(void)
{
	ftCont();
	// stdCont();
	return (0);
}
