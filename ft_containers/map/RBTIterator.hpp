#ifndef RBTIterator_hpp
#define RBTIterator_hpp

#include "../iterator/iterator.hpp"

namespace ft {

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator synopsis
//--------------------------------------------------------------

template <class Node, class Compare>
class RBTIterator : public ft::iterator<ft::bidirectional_iterator_tag, Node>
{
	public:
	// member types
	typedef typename Node::value_type																value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

	public:
	// constructor
	RBTIterator(const Compare& comp = Compare());
	RBTIterator(Node* startNode, const Compare& comp = Compare());
	RBTIterator(Node* startNode, Node* leafNode, const Compare& comp = Compare());
	RBTIterator(const RBTIterator& it);

	// destructor
	~RBTIterator();

	// operator overloading
	RBTIterator&		operator=(const RBTIterator& it);
	reference			operator*(void) const;
	pointer				operator->(void) const;
	RBTIterator&		operator++(void);
	RBTIterator			operator++(int);
	RBTIterator&		operator--(void);
	RBTIterator			operator--(int);
	bool				operator==(const RBTIterator& op) const;
	bool				operator!=(const RBTIterator& op) const;

	private:
	// member variable
	Node		*_startNode;
	Node		*_leafNode;
	Compare		_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator definition
//--------------------------------------------------------------

template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(const Compare& comp) :
	_startNode(),
	_leafNode(),
	_comp(comp)
{}

template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(Node* startNode, const Compare& comp) :
	_startNode(startNode),
	_leafNode(),
	_comp(comp)
{}

template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(Node* newNode, Node * leafNode, const Compare& comp) :
	_startNode(newNode),
	_leafNode(leafNode),
	_comp(comp)
{}

template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(const RBTIterator& it) :
	_startNode(it._startNode),
	_leafNode(it._leafNode),
	_comp(it._comp)
{}

template <class Node, class Compare>
RBTIterator<Node, Compare>::~RBTIterator()
{}

template <class Node, class Compare>
RBTIterator<Node, Compare>&
RBTIterator<Node, Compare>::operator=(const RBTIterator &it)
{
	if (this == &it)
		return (*this);
	_startNode = it._startNode;
	_comp = it._comp;
	return (*this);
}

template <class Node, class Compare>
typename RBTIterator<Node, Compare>::reference
RBTIterator<Node, Compare>::operator*(void) const
{
	return (_startNode->_value);
}


template <class Node, class Compare>
typename RBTIterator<Node, Compare>::pointer
RBTIterator<Node, Compare>::operator->(void) const
{
	return (&(_startNode->_value));
}


// template <class Node, class Compare>
// RBTIterator<Node, Compare>&
// RBTIterator<Node, Compare>::operator++(void)
// {
//
// }
//
// template <class Node, class Compare>
// RBTIterator<Node, Compare>
// RBTIterator<Node, Compare>::operator++(int)
// {
//
// }
//
// template <class Node, class Compare>
// RBTIterator<Node, Compare>&
// RBTIterator<Node, Compare>::operator--(void)
// {
//
// }
//
//
// template <class Node, class Compare>
// RBTIterator<Node, Compare>
// RBTIterator<Node, Compare>::operator--(int)
// {
//
// }

template <class Node, class Compare>
bool
RBTIterator<Node, Compare>::operator==(const RBTIterator& op) const
{
	return (_startNode == op._startNode);
}

template <class Node, class Compare>
bool
RBTIterator<Node, Compare>::operator!=(const RBTIterator& op) const
{
	return (_startNode != op._startNode);
}

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::const_RBTIterator synopsis
//--------------------------------------------------------------

template <class Node, class Compare>
class const_RBTIterator : public ft::iterator<bidirectional_iterator_tag, Node>
{
	public :

};


}

#endif
