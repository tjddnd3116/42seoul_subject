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
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, Node>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, Node>::value_type			value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, Node>::difference_type	difference_type;
	typedef Node*																			pointer;
	typedef Node&																			reference;

	public:
	// constructor
	RBTIterator(const Compare& comp = Compare());
	RBTIterator(Node* node, const Compare& comp = Compare());
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
	Node		*_node;
	Compare		_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator definition
//--------------------------------------------------------------

template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(const Compare& comp) : _node(), _comp(comp)
{}

template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(Node* node, const Compare& comp) : _node(node), _comp(comp)
{}


template <class Node, class Compare>
RBTIterator<Node, Compare>::RBTIterator(const RBTIterator& it) : _node(it._node), _comp(it._comp)
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
	_node = it._node;
	_comp = it._comp;
	return (*this);
}

template <class Node, class Compare>
typename RBTIterator<Node, Compare>::reference
RBTIterator<Node, Compare>::operator*(void) const
{
	return (_node->value);
}


template <class Node, class Compare>
typename RBTIterator<Node, Compare>::pointer
RBTIterator<Node, Compare>::operator->(void) const
{
	return (&_node->value);
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
	return (_node == op._node);
}

template <class Node, class Compare>
bool
RBTIterator<Node, Compare>::operator!=(const RBTIterator& op) const
{
	return (_node != op._node);
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
