#include "./vector/vector.hpp"
#include <exception>
#include <iterator>
#include <algorithm>
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
	std::vector<std::string> realVec;
	realVec.push_back("1");
	realVec.push_back("2");
	realVec.push_back("3");
	realVec.push_back("4");
	realVec.push_back("5");
	std::cout << "before" << std::endl;
	std::cout << "	size : " << realVec.size() << std::endl;
	std::cout << "	capacity :" << realVec.capacity() << std::endl;
	for(std::vector<std::string>::iterator it = realVec.begin(); it != realVec.end(); it++)
		std::cout << "	" << *it << std::endl;

	std::vector<std::string>::iterator it;
	it = realVec.begin();
	realVec.erase(it, it + 4);
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
	ft::vector<std::string> myVec(5, "42");
	ft::vector<std::string> myVec2(myVec);
	// std::cout << "before" << std::endl;
	// std::cout << "	size : " << myVec.size() << std::endl;
	// std::cout << "	capacity :" << myVec.capacity() << std::endl;
	// for(ft::vector<std::string>::iterator it = myVec.begin(); it != myVec.end(); it++)
	//     std::cout << "	" << *it << std::endl;

	// myVec.swap(myVec2);
	// std::cout << "after" << std::endl;
	std::cout << "myVec	size : "<< myVec.size() << std::endl;
	std::cout << "myVec	capacity :" << myVec.capacity() << std::endl;
	for(ft::vector<std::string>::iterator it = myVec.begin(); it != myVec.end(); it++)
		std::cout << "	" << *it << std::endl;
	std::cout << "--------" << std::endl;
	std::cout << "myVec2	size : "<< myVec2.size() << std::endl;
	std::cout << "myVec2	capacity :" << myVec2.capacity() << std::endl;
	for(ft::vector<std::string>::iterator it = myVec2.begin(); it != myVec2.end(); it++)
		std::cout << "	" << *it << std::endl;
	std::cout << "-------myVector--------" << std::endl;
}

int main(void)
{
	myVector();
	// realVector();
	// system("leaks a.out");
	return (0);
}
