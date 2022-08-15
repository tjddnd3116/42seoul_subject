#ifndef newset_hpp
#define newset_hpp

#include "../utils/funtional.hpp"
#include "../iterator/reverseIterator.hpp"
#include "../utils/algorithm.hpp"
#include "../map/map.hpp"
#include <memory>



namespace ft {

template < class T,
		 class Compare = ft::less<T>,
		 class Alloc = std::allocator<T> >
class set : public ft::map<T, T>
{

};


}

#endif
