#include "./vector/vector.hpp"
// #include "./stack/stack.hpp"
// #include "./utils/utility.hpp"
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
	// ft::map<int, int> copyMap;
	ft::map<int, int>::const_iterator beginIt;
	ft::map<int, int>::const_iterator endIt;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ret;

	ft::vector<int> myVec;
	myVec.push_back(1);
	ft::vector<int>::const_iterator vecIt;
	vecIt = myVec.begin();


	// std::cout << "-----insert 8-----" << std::endl;
	myMap.insert(ft::pair<int, int>(17, 42));
	// // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 18-----" << std::endl;
	myMap.insert(ft::pair<int, int>(15, 42));
	// // // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 5-----" << std::endl;
	myMap.insert(ft::pair<int, int>(10, 42));
	// // // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 15-----" << std::endl;
	myMap.insert(ft::pair<int, int>(13, 42));
	// // // // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 17-----" << std::endl;
	myMap.insert(ft::pair<int, int>(16, 42));
	// // // // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 25-----" << std::endl;
	myMap.insert(ft::pair<int, int>(25, 42));
	// // // // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 40-----" << std::endl;
	myMap.insert(ft::pair<int, int>(18, 42));
	myMap.insert(ft::pair<int, int>(19, 42));
	// // // // std::cout << ret.first->first << std::endl;
	// std::cout << "-----insert 80-----" << std::endl;
	myMap.insert(ft::pair<int, int>(40, 42));
	myMap.insert(ft::pair<int, int>(1, 42));
	myMap.insert(ft::pair<int, int>(42, 42));
	myMap.insert(ft::pair<int, int>(7, 42));
	myMap.insert(ft::pair<int, int>(3, 42));
	myMap.insert(ft::pair<int, int>(22, 42));
	// std::cout << myMap.size() << std::endl;
	// copyMap.swap(myMap);
	ft::map<int, int> copyMap = myMap;
	beginIt = myMap.begin();
	endIt = myMap.end();
	for (; beginIt != endIt; beginIt++)
		std::cout << beginIt->first << std::endl;
	std::cout << "--------------" << std::endl;
	beginIt = copyMap.begin();
	endIt = copyMap.end();
	for (; beginIt != endIt; beginIt++)
		std::cout << beginIt->first << std::endl;
	std::cout << "-------ftCont--------" << std::endl;
}

int main(void)
{
	ftCont();
	// stdCont();
	// system("leaks a.out");
	return (0);
}
