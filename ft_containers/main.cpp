#include "./vector/vector.hpp"
#include <cmath>
#include <exception>
#include <iterator>
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>

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

void	realVector(void)
{
	std::cout << "-------realVector--------" << std::endl;
	std::vector<std::string> realVec(10, "42");
	std::vector<std::string> realVec2(4, "21");
	std::cout << "before" << std::endl;
	std::cout << "	size : " << realVec.size() << std::endl;
	std::cout << "	capacity :" << realVec.capacity() << std::endl;
	for(std::vector<std::string>::iterator it = realVec.begin(); it != realVec.end(); it++)
		std::cout << "	" << *it << std::endl;

	realVec2.assign(realVec.begin(), realVec.end());
	std::cout << "after" << std::endl;
	std::cout << "	size : "<< realVec2.size() << std::endl;
	std::cout << "	capacity :" << realVec2.capacity() << std::endl;
	for(std::vector<std::string>::iterator it = realVec2.begin(); it != realVec2.end(); it++)
		std::cout << "	" << *it << std::endl;
	std::cout << "-------realVector--------" << std::endl;
}

void	myVector(void)
{
	std::cout << "-------myVector--------" << std::endl;
	ft::vector<int> myVec;

	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	std::cout << "--------before" << std::endl;
	std::cout << " size : " << myVec.size() << std::endl;
	std::cout << " capacity : " << myVec.capacity() << std::endl;
	for(ft::vector<int>::const_reverse_iterator it = myVec.rbegin(); it != myVec.rend(); it++)
		std::cout << "	" << *it << std::endl;
	// myVec.insert(myVec.begin(), myVec.begin(), myVec.end());
	// myVec.insert(myVec.end(), 5,  myVec.front());
	// std::cout << "--------after" << std::endl;
	// std::cout << " size : " << myVec.size() << std::endl;
	// std::cout << " capacity : " << myVec.capacity() << std::endl;
	// for(ft::vector<int>::reverse_iterator it = myVec.rbegin(); it != myVec.rend(); it++)
	//     std::cout << "	" << *it << std::endl;
	// std::cout << "-------myVector--------" << std::endl;
}

int main(void)
{
	myVector();
	// realVector();
	// system("leaks a.out");
	return (0);
}
