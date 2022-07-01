#include "./vector/vector.hpp"
#include <iterator>
#include <algorithm>
#include <vector>

int main(void)
{
	ft::vector<std::string> myVec(3, "42");
	std::vector<std::string> realVec(3, "42");


	ft::vector<std::string>::const_iterator beginIt;
	ft::vector<std::string>::iterator endIt;

	std::vector<std::string>::const_iterator realBeginIt;
	std::vector<std::string>::iterator realEndIt;

	beginIt = myVec.begin();
	endIt = myVec.end();

	realBeginIt = realVec.begin();
	realEndIt = realVec.end();

	std::cout << *beginIt << std::endl;
	std::cout << *realBeginIt << std::endl;

	return (0);
}
