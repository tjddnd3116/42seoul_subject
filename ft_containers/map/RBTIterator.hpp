#ifndef RBTIterator_hpp
#define RBTIterator_hpp

#include "../iterator/iterator.hpp"

namespace ft {

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator synopsis
//--------------------------------------------------------------

template <class node, class Compare>
class RBTIterator : public ft::iterator<ft::bidirectional_iterator_tag, node>
{
	public:
	// member types
	typedef typename node::value_type																value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

	public:
	// constructor
	RBTIterator(const Compare& comp = Compare());
	RBTIterator(node* startNode, const Compare& comp = Compare());
	RBTIterator(node* startNode, node* leafNode, const Compare& comp = Compare());
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
	node		*_startNode;
	node		*_leafNode;
	Compare		_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator definition
//--------------------------------------------------------------

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(const Compare& comp) :
	_startNode(),
	_leafNode(),
	_comp(comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(node* startNode, const Compare& comp) :
	_startNode(startNode),
	_leafNode(),
	_comp(comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(node* newNode, node * leafNode, const Compare& comp) :
	_startNode(newNode),
	_leafNode(leafNode),
	_comp(comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(const RBTIterator& it) :
	_startNode(it._startNode),
	_leafNode(it._leafNode),
	_comp(it._comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::~RBTIterator()
{}

template <class node, class Compare>
RBTIterator<node, Compare>&
RBTIterator<node, Compare>::operator=(const RBTIterator &it)
{
	if (this == &it)
		return (*this);
	_startNode = it._startNode;
	_comp = it._comp;
	return (*this);
}

template <class node, class Compare>
typename RBTIterator<node, Compare>::reference
RBTIterator<node, Compare>::operator*(void) const
{
	return (_startNode->_value);
}


template <class node, class Compare>
typename RBTIterator<node, Compare>::pointer
RBTIterator<node, Compare>::operator->(void) const
{
	return (&(_startNode->_value));
}


template <class node, class Compare>
RBTIterator<node, Compare>&
RBTIterator<node, Compare>::operator++(void)
{
	node*	curNode;

	curNode = _startNode;

}

template <class node, class Compare>
RBTIterator<node, Compare>
RBTIterator<node, Compare>::operator++(int)
{
	RBTIterator tmp(*this);
	operator++();
	return (tmp);
}

// template <class node, class Compare>
// RBTIterator<node, Compare>&
// RBTIterator<node, Compare>::operator--(void)
// {
//
// }


template <class node, class Compare>
RBTIterator<node, Compare>
RBTIterator<node, Compare>::operator--(int)
{
	RBTIterator tmp(*this);
	operator--();
	return (tmp);
}

template <class node, class Compare>
bool
RBTIterator<node, Compare>::operator==(const RBTIterator& op) const
{
	return (_startNode == op._startNode);
}

template <class node, class Compare>
bool
RBTIterator<node, Compare>::operator!=(const RBTIterator& op) const
{
	return (_startNode != op._startNode);
}

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::const_RBTIterator synopsis
//--------------------------------------------------------------

template <class node, class Compare>
class const_RBTIterator : public ft::iterator<ft::bidirectional_iterator_tag, node>
{
	public:
	// member types
	typedef typename node::value_type																value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

	public:
	// constructor
	RBTIterator(const Compare& comp = Compare());
	RBTIterator(node* startNode, const Compare& comp = Compare());
	RBTIterator(node* startNode, node* leafNode, const Compare& comp = Compare());
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
	node		*_startNode;
	node		*_leafNode;
	Compare		_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator definition
//--------------------------------------------------------------

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(const Compare& comp) :
	_startNode(),
	_leafNode(),
	_comp(comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(node* startNode, const Compare& comp) :
	_startNode(startNode),
	_leafNode(),
	_comp(comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(node* newNode, node * leafNode, const Compare& comp) :
	_startNode(newNode),
	_leafNode(leafNode),
	_comp(comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(const RBTIterator& it) :
	_startNode(it._startNode),
	_leafNode(it._leafNode),
	_comp(it._comp)
{}

template <class node, class Compare>
RBTIterator<node, Compare>::~RBTIterator()
{}

template <class node, class Compare>
RBTIterator<node, Compare>&
RBTIterator<node, Compare>::operator=(const RBTIterator &it)
{
	if (this == &it)
		return (*this);
	_startNode = it._startNode;
	_comp = it._comp;
	return (*this);
}

template <class node, class Compare>
typename RBTIterator<node, Compare>::reference
RBTIterator<node, Compare>::operator*(void) const
{
	return (_startNode->_value);
}


template <class node, class Compare>
typename RBTIterator<node, Compare>::pointer
RBTIterator<node, Compare>::operator->(void) const
{
	return (&(_startNode->_value));
}


template <class node, class Compare>
RBTIterator<node, Compare>&
RBTIterator<node, Compare>::operator++(void)
{
	node*	curNode;

	curNode = _startNode;

}

template <class node, class Compare>
RBTIterator<node, Compare>
RBTIterator<node, Compare>::operator++(int)
{
	RBTIterator tmp(*this);
	operator++();
	return (tmp);
}

// template <class node, class Compare>
// RBTIterator<node, Compare>&
// RBTIterator<node, Compare>::operator--(void)
// {
//
// }


template <class node, class Compare>
RBTIterator<node, Compare>
RBTIterator<node, Compare>::operator--(int)
{
	RBTIterator tmp(*this);
	operator--();
	return (tmp);
}

template <class node, class Compare>
bool
RBTIterator<node, Compare>::operator==(const RBTIterator& op) const
{
	return (_startNode == op._startNode);
}

template <class node, class Compare>
bool
RBTIterator<node, Compare>::operator!=(const RBTIterator& op) const
{
	return (_startNode != op._startNode);
}


}

#endif
