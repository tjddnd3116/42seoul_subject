#include "./vector/vector.hpp"
#include <iterator>

int main(void)
{
	ft::vector<int> myVec;
	ft::vector<int> myVec1(14, 4);
	myVec1.print_val();

	return (0);
}
