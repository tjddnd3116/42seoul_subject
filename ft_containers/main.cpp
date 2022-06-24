#include "./vector/vector.hpp"
#include <iterator>
#include <algorithm>

int main(void)
{
	ft::vector<std::string> myVec1(1, "42");

	ft::vector<std::string>::iterator it;
	it = myVec1.begin();

	std::cout << *it << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *it << std::endl;
	// std::cout << *(++it) << std::endl;
	// std::cout << *(++it) << std::endl;
	return (0);
}
