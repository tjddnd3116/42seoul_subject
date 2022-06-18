#include "./vector/vector.hpp"
#include <iterator>

int main(void)
{
	ft::vector<int> myVec;
	ft::vector<int> myVec1(14, 4);
	std::cout << myVec1.size() << std::endl;

	ft::vector<int>::iterator it;

	return (0);
}
