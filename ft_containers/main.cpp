#include "./vector/vector.hpp"
#include <iterator>
#include <algorithm>
#include <vector>

int main(void)
{
	// ft::vector<std::string> myVec(3, "42");
	std::vector<std::string> realVec(5, "42");

	std::cout << realVec.capacity() << std::endl;
	realVec.resize(13);
	// for (std::vector<std::string>::iterator it = realVec.begin(); it != realVec.end(); it++)
	//     std::cout << *it << std::endl;
	std::cout << realVec.capacity() << std::endl;


	return (0);
}
