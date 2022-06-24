#include "./vector/vector.hpp"
#include <iterator>
#include <algorithm>

int main(void)
{
	// ft::vector<int> myVec;
	ft::vector<int> myVec1(14, 4);
	// std::cout << myVec1.size() << std::endl;

	ft::vector<int>::iterator it;
	// std::cout << myVec1.begin() << std::endl;
	it = myVec1.begin();

	std::cout << *it << std::endl;
	return (0);
}
