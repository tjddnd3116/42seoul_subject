#include "./vector/vector.hpp"
#include <iterator>
#include <algorithm>

int main(void)
{
	ft::vector<int> myVec;
	ft::vector<int> myVec1(14, 4);
	std::cout << myVec1.size() << std::endl;

	ft::vector<int>::iterator it;

	it = myVec1.begin();

	return (0);
}
