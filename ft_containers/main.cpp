#include "./vector/vector.hpp"
#include "./stack/stack.hpp"
#include "./utils/utility.hpp"
#include "./map/map.hpp"
#include "./set/set.hpp"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <functional>
#include <iterator>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <list>

class myClass
{
	private:
		std::string _name;
	public:
		myClass()
		{
			// std::cout << "constructor call" << std::endl;
			_name = "no_name";
		}
		myClass(const myClass& op)
		{
			// std::cout << "copy constructor call" << std::endl;
			_name = op._name;
		}
		myClass(std::string& newName)
		{
			// std::cout << "constructor call" << std::endl;
			_name = newName;
		}
		~myClass()
		{
			// std::cout << "destructor call" << std::endl;
		}
		myClass& operator=(const myClass& rhs)
		{
			// std::cout << "copy assignment operator call" << std::endl;
			_name = rhs._name;
			return (*this);
		}
		void m(void)
		{
			std::cout << "non const function" << std::endl;
		}
		void m(void) const
		{
			std::cout << "const function" << std::endl;
		}
};

void	stdCont(void)
{
	std::cout << "-------stdCont--------" << std::endl;
	// std::map<std::string, int, std::greater<std::string> > stdMap;
	std::map<int, int > stdMap;
	std::map<int, int>::iterator MapIt;
	// std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> ret;
	stdMap.insert(std::make_pair(100, 2));
	stdMap.insert(std::pair<int, int>(10, 2));
	stdMap.insert(std::pair<int, int>(15, 1));
	stdMap.insert(std::pair<int, int>(1, 5));
	stdMap.insert(std::pair<int, int>(3, 4));
	stdMap.insert(std::pair<int, int>(5, 3));
	// MapIt = stdMap.end();
	stdMap.erase(stdMap.end(), stdMap.end());
	// std::cout << stdMap.size() << std::endl;
	// mapIt = stdMap.upper_bound(14);
	// ret = stdMap.equal_range(15);
	// std::cout << ret.first->first << std::endl;
	// std::cout << ret.first->second << std::endl;
	// std::cout << "-------------" << std::endl;
	// std::cout << (--ret.second)->first << std::endl;
	// std::cout << (--ret.second)->second << std::endl;
	std::cout << "-------stdCont--------" << std::endl;
}

void	ftCont(void)
{
	ft::vector<myClass> aa(2);

	ft::vector<myClass>::iterator it = aa.begin();
	ft::vector<myClass>::const_iterator ite = aa.begin();

	it->m();
	ite->m();

}
int main(void)
{
	ftCont();
	// stdCont();
	// system("leaks a.out");
	return (0);
}
