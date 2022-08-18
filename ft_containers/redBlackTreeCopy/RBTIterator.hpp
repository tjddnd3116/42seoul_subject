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
	// RBTIterator(node* startNode, const Compare& comp = Compare());
	RBTIterator(node* startNode, node* leafNode, const Compare& comp = Compare());
	RBTIterator(const RBTIterator& it);

	// destructor
	~RBTIterator();

	// operator overloading
	RBTIterator&	operator=(const RBTIterator& it);
	reference		operator*(void) const;
	pointer			operator->(void) const;
	RBTIterator&	operator++(void);
	RBTIterator		operator++(int);
	RBTIterator&	operator--(void);
	RBTIterator		operator--(int);
	bool			operator==(const RBTIterator& op) const;
	bool			operator!=(const RBTIterator& op) const;

	// private:
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

// template <class node, class Compare>
// RBTIterator<node, Compare>::RBTIterator(node* startNode, const Compare& comp) :
//     _startNode(startNode),
//     _leafNode(),
//     _comp(comp)
// {}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(node* newNode, node* leafNode, const Compare& comp) :
	_comp(comp)
{
	_startNode = newNode;
	_leafNode = leafNode;
}

template <class node, class Compare>
RBTIterator<node, Compare>::RBTIterator(const RBTIterator& it) :
	_comp(it._comp)
{
	_startNode = it._startNode;
	_leafNode = it._leafNode;
}

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
	_leafNode = it._leafNode;
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
	if (_startNode == _leafNode)
		return (NULL);
	return (&(_startNode->_value));
}


template <class node, class Compare>
RBTIterator<node, Compare>&
RBTIterator<node, Compare>::operator++(void)
{
	node*	curNode;

	if (_startNode == NULL)
		return (*this);
	curNode = _startNode;
	if (curNode->_right != _leafNode) // 시작 노드의 오른쪽 자식이 있을때
	{
		curNode = curNode->_right;
		while (curNode->_left != _leafNode)
			curNode = curNode->_left;
	}
	else if (curNode != _leafNode)	// 시작 노드가 리프노드가 아닐때
	{
		curNode = curNode->_parent;
		while (curNode != _leafNode && _comp(curNode->_value.first, _startNode->_value.first))
			curNode = curNode->_parent;
	}
	else if (curNode == _leafNode)
	{
		curNode = NULL;
	}
	_startNode = curNode;
	return (*this);
}

template <class node, class Compare>
RBTIterator<node, Compare>
RBTIterator<node, Compare>::operator++(int)
{
	RBTIterator tmp(*this);
	operator++();
	return (tmp);
}

template <class node, class Compare>
RBTIterator<node, Compare>&
RBTIterator<node, Compare>::operator--(void)
{
	node* curNode;

	if (_startNode == NULL)
		return (*this);
	curNode = _startNode;
	if (curNode->_left != _leafNode)
	{
		curNode = curNode->_left;
		while (curNode->_right != _leafNode)
			curNode = curNode->_right;
	}
	else if (curNode != _leafNode)
	{
		curNode = curNode->_parent;
		while (curNode != _leafNode && _comp(_startNode->_value.first, curNode->_value.first))
			curNode = curNode->_parent;
		if (curNode == _leafNode)
			curNode = NULL;
	}
	else if (curNode == _leafNode)
	{
		curNode = curNode->_parent;
		while (curNode->_right != _leafNode)
			curNode = curNode->_right;
	}
	_startNode = curNode;
	return (*this);
}


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
	const_RBTIterator(const Compare& comp = Compare());
	// const_RBTIterator(node* startNode, const Compare& comp = Compare());
	const_RBTIterator(node* startNode, node* leafNode, const Compare& comp = Compare());
	const_RBTIterator(const const_RBTIterator& it);
	const_RBTIterator(const RBTIterator<node, Compare>& it);

	// destructor
	~const_RBTIterator();

	// operator overloading
	const_RBTIterator&	operator=(const const_RBTIterator& it);
	reference			operator*(void) const;
	pointer				operator->(void) const;
	const_RBTIterator&	operator++(void);
	const_RBTIterator	operator++(int);
	const_RBTIterator&	operator--(void);
	const_RBTIterator	operator--(int);
	bool				operator==(const const_RBTIterator& op) const;
	bool				operator!=(const const_RBTIterator& op) const;

	// private:
	// member variable
	node		*_startNode;
	node		*_leafNode;
	Compare		_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::const_RBTIterator definition
//--------------------------------------------------------------

template <class node, class Compare>
const_RBTIterator<node, Compare>::const_RBTIterator(const Compare& comp) :
	_startNode(),
	_leafNode(),
	_comp(comp)
{}

// template <class node, class Compare>
// const_RBTIterator<node, Compare>::const_RBTIterator(node* startNode, const Compare& comp) :
//     _startNode(startNode),
//     _leafNode(),
//     _comp(comp)
// {}

template <class node, class Compare>
const_RBTIterator<node, Compare>::const_RBTIterator(node* newNode, node* leafNode, const Compare& comp) :
	_comp(comp)
{
	_startNode = newNode;
	_leafNode = leafNode;
}

template <class node, class Compare>
const_RBTIterator<node, Compare>::const_RBTIterator(const const_RBTIterator& it) :
	_comp(it._comp)
{
	_startNode = it._startNode;
	_leafNode = it._leafNode;
}

template <class node, class Compare>
const_RBTIterator<node, Compare>::const_RBTIterator(const RBTIterator<node, Compare>& it) :
	_comp(it._comp)
{
	_startNode = it._startNode;
	_leafNode = it._leafNode;
}

template <class node, class Compare>
const_RBTIterator<node, Compare>::~const_RBTIterator()
{}

template <class node, class Compare>
const_RBTIterator<node, Compare>&
const_RBTIterator<node, Compare>::operator=(const const_RBTIterator &it)
{
	if (this == &it)
		return (*this);
	_startNode = it._startNode;
	_comp = it._comp;
	_leafNode = it._leafNode;
	return (*this);
}

template <class node, class Compare>
typename const_RBTIterator<node, Compare>::reference
const_RBTIterator<node, Compare>::operator*(void) const
{
	return (_startNode->_value);
}


template <class node, class Compare>
typename const_RBTIterator<node, Compare>::pointer
const_RBTIterator<node, Compare>::operator->(void) const
{
	if (_startNode == _leafNode)
		return (NULL);
	return (&(_startNode->_value));
}


template <class node, class Compare>
const_RBTIterator<node, Compare>&
const_RBTIterator<node, Compare>::operator++(void)
{
	node*	curNode;

	if (_startNode == NULL)
		return (*this);
	curNode = _startNode;
	if (curNode->_right != _leafNode) // 시작 노드의 오른쪽 자식이 있을때
	{
		curNode = curNode->_right;
		while (curNode->_left != _leafNode)
			curNode = curNode->_left;
	}
	else if (curNode != _leafNode)	// 시작 노드가 리프노드가 아닐때
	{
		curNode = curNode->_parent;
		while (curNode != _leafNode && _comp(curNode->_value.first, _startNode->_value.first))
			curNode = curNode->_parent;
	}
	else if (curNode == _leafNode)
	{
		curNode = NULL;
	}
	_startNode = curNode;
	return (*this);

}

template <class node, class Compare>
const_RBTIterator<node, Compare>
const_RBTIterator<node, Compare>::operator++(int)
{
	const_RBTIterator tmp(*this);
	operator++();
	return (tmp);
}

template <class node, class Compare>
const_RBTIterator<node, Compare>&
const_RBTIterator<node, Compare>::operator--(void)
{
	node* curNode;

	if (_startNode == NULL)
		return (*this);
	curNode = _startNode;
	if (curNode->_left != _leafNode)
	{
		curNode = curNode->_left;
		while (curNode->_right != _leafNode)
			curNode = curNode->_right;
	}
	else if (curNode != _leafNode)
	{
		curNode = curNode->_parent;
		while (curNode != _leafNode && _comp(_startNode->_value.first, curNode->_value.first))
			curNode = curNode->_parent;
		if (curNode == _leafNode)
			curNode = NULL;
	}
	else if (curNode == _leafNode)
	{
		curNode = curNode->_parent;
		while (curNode->_right != _leafNode)
			curNode = curNode->_right;
	}
	_startNode = curNode;
	return (*this);

}

template <class node, class Compare>
const_RBTIterator<node, Compare>
const_RBTIterator<node, Compare>::operator--(int)
{
	const_RBTIterator tmp(*this);
	operator--();
	return (tmp);
}

template <class node, class Compare>
bool
const_RBTIterator<node, Compare>::operator==(const const_RBTIterator& op) const
{
	return (_startNode == op._startNode);
}

template <class node, class Compare>
bool
const_RBTIterator<node, Compare>::operator!=(const const_RBTIterator& op) const
{
	return (_startNode != op._startNode);
}

}
#endif
