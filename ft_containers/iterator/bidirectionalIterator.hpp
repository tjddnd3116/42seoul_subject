#ifndef bidirectionalIterator_hpp
#define bidirectionalIterator_hpp

#include "iterator.hpp"
namespace ft {

//---------------------------------------
//   bidirectional_iterator<T> synopsis
//---------------------------------------
//
template <typename T>
class	bidirectional_iterator : iterator<bidirectional_iterator_tag, T>
{
	public:
	// member types
	typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T*																	pointer;
	typedef T&																	reference;

	// constructor


	// destructor


	// operator overloading
	private :
	pointer _ptr;
};

}
#endif
