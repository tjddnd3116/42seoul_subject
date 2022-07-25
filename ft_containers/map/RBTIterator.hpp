#ifndef RBTIterator_hpp
#define RBTIterator_hpp

#include "./redBlackTree.hpp"

namespace ft {


//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator synopsis
//--------------------------------------------------------------
template <class Key, class T, class Compare, class Alloc>
class redBlackTree<Key, T, Compare, Alloc>::RBTIterator : public ft::bidirectional_iterator<T>
{
	public:
	// member types
	typedef typename bidirectional_iterator<T>::iterator_category	iterator_category;
	typedef typename bidirectional_iterator<T>::value_type			value_type;
	typedef typename bidirectional_iterator<T>::difference_type		difference_type;
	typedef T*														pointer;
	typedef T&														reference;

	RBTIterator(void);
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::const_RBTIterator synopsis
//--------------------------------------------------------------

template <class Key, class T, class Compare, class Alloc>
class redBlackTree<Key, T, Compare, Alloc>::const_RBTIterator : public ft::bidirectional_iterator<T>
{

};


}

#endif
