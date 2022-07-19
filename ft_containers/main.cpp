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
	std::vector<std::string> realVec(3, "42");
	std::cout << "before" << std::endl;
	std::cout << "	size : " << realVec.size() << std::endl;
	std::cout << "	capacity :" << realVec.capacity() << std::endl;
	for(std::vector<std::string>::iterator it = realVec.begin(); it != realVec.end(); it++)
		std::cout << "	" << *it << std::endl;

	std::vector<std::string>::iterator it;
	it = realVec.end();
	realVec.insert(it, 2, "4");
	std::cout << "after" << std::endl;
	std::cout << "	size : "<< realVec.size() << std::endl;
	std::cout << "	capacity :" << realVec.capacity() << std::endl;
	for(std::vector<std::string>::iterator it = realVec.begin(); it != realVec.end(); it++)
		std::cout << "	" << *it << std::endl;
	std::cout << "-------realVector--------" << std::endl;
}

void	myVector(void)
{
	std::cout << "-------myVector--------" << std::endl;
	ft::vector<int> myVec(3, 42);
	ft::vector<int>::iterator it;


	std::cout << "--------before" << std::endl;
	std::cout << " size : " << myVec.size() << std::endl;
	std::cout << " capacity : " << myVec.capacity() << std::endl;
	for(ft::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		std::cout << "	" << *it << std::endl;
	it = myVec.end();
	myVec.insert(it, 2, 4);
	// myVec.insert(myVec.end(), 5, myVec.front());
	std::cout << "--------after" << std::endl;
	std::cout << " size : " << myVec.size() << std::endl;
	std::cout << " capacity : " << myVec.capacity() << std::endl;
	for(ft::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		std::cout << "	" << *it << std::endl;
	// std::cout << "-------myVector--------" << std::endl;
}

int main(void)
{
	// myVector();
	realVector();
	// system("leaks a.out");
	return (0);
}
