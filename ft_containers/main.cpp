#include "./vector/vector.hpp"
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main(void)
{
	ft::vector<std::string> myVec(5, "42");
	// std::vector<std::string> realVec(5, "42");
	myVec.reserve(10);

	std::cout << "capacity :" << myVec.capacity() << std::endl;
	std::cout << "size :" << myVec.size() << std::endl;
	for (ft::vector<std::string>::iterator it = myVec.begin(); it != myVec.end(); it++)
		std::cout << *it << std::endl;

	myVec.resize(15);
	std::cout << "capacity :" << myVec.capacity() << std::endl;
	std::cout << "size :" << myVec.size() << std::endl;
	for (ft::vector<std::string>::iterator it = myVec.begin(); it != myVec.end(); it++)
		std::cout << *it << std::endl;
	// realVec.resize(1, "0");
	// std::cout << "capacity :" << realVec.capacity() << std::endl;
	// std::cout << "size :" << realVec.size() << std::endl;
	// for (std::vector<std::string>::iterator it = realVec.begin(); it != realVec.end(); it++)
	//     std::cout << *it << std::endl;

	return (0);
}
