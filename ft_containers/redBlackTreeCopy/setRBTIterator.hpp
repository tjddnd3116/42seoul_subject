#ifndef setRBTIterator_hpp
#define setRBTIterator_hpp

#include "../iterator/iterator.hpp"
#include "./RBTNode.hpp"

namespace ft {

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::RBTIterator synopsis
//--------------------------------------------------------------


template <class node, class Compare>
class setRBTIterator : public ft::iterator<ft::bidirectional_iterator_tag, node>
{
	public:
	// member types
	typedef typename node::value_type																value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
	typedef value_type* pointer;
	typedef value_type	reference;

	public:
	// constructor
	setRBTIterator(const Compare& comp = Compare());
	setRBTIterator(node* startNode, node* leafNode, const Compare& comp = Compare());
	setRBTIterator(const setRBTIterator& it);

	// destructor
	~setRBTIterator();

	// operator overloading
	setRBTIterator&	operator=(const setRBTIterator& it);
	const reference	operator*(void) const;
	pointer			operator->(void) const;
	setRBTIterator&	operator++(void);
	setRBTIterator	operator++(int);
	setRBTIterator&	operator--(void);
	setRBTIterator	operator--(int);
	bool			operator==(const setRBTIterator& op) const;
	bool			operator!=(const setRBTIterator& op) const;

	// member variable
	node*		_startNode;
	node*		_leafNode;
	Compare		_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::setRBTIterator definition
//--------------------------------------------------------------

template <class node, class Compare>
setRBTIterator<node, Compare>::setRBTIterator(const Compare& comp) :
	_startNode(),
	_leafNode(),
	_comp(comp)
{}

template <class node, class Compare>
setRBTIterator<node, Compare>::setRBTIterator(node* newNode, node* leafNode, const Compare& comp) :
	_comp(comp)
{
	_startNode = newNode;
	_leafNode = leafNode;
}

template <class node, class Compare>
setRBTIterator<node, Compare>::setRBTIterator(const setRBTIterator& it) :
	_comp(it._comp)
{
	_startNode = it._startNode;
	_leafNode = it._leafNode;
}

template <class node, class Compare>
setRBTIterator<node, Compare>::~setRBTIterator()
{}

template <class node, class Compare>
setRBTIterator<node, Compare>&
setRBTIterator<node, Compare>::operator=(const setRBTIterator& it)
{
	if (this == &it)
		return (*this);
	_startNode = it._startNode;
	_comp = it._comp;
	_leafNode = it._leafNode;
	return (*this);
}

template <class node, class Compare>
const typename setRBTIterator<node, Compare>::reference
setRBTIterator<node, Compare>::operator*(void) const
{
	const typename node::value_type val = _startNode->_value;
	return (val);
	// return (_startNode->_value);
}


template <class node, class Compare>
typename setRBTIterator<node, Compare>::pointer
setRBTIterator<node, Compare>::operator->(void) const
{
	if (_startNode == _leafNode)
		return (NULL);
	return (&(_startNode->_value));
}


template <class node, class Compare>
setRBTIterator<node, Compare>&
setRBTIterator<node, Compare>::operator++(void)
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
		while (curNode != _leafNode && _comp(curNode->_value, _startNode->_value))
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
setRBTIterator<node, Compare>
setRBTIterator<node, Compare>::operator++(int)
{
	setRBTIterator tmp(*this);
	operator++();
	return (tmp);
}

template <class node, class Compare>
setRBTIterator<node, Compare>&
setRBTIterator<node, Compare>::operator--(void)
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
		while (curNode != _leafNode && _comp(_startNode->_value, curNode->_value))
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
setRBTIterator<node, Compare>
setRBTIterator<node, Compare>::operator--(int)
{
	setRBTIterator tmp(*this);
	operator--();
	return (tmp);
}

template <class node, class Compare>
bool
setRBTIterator<node, Compare>::operator==(const setRBTIterator& op) const
{
	return (_startNode == op._startNode);
}

template <class node, class Compare>
bool
setRBTIterator<node, Compare>::operator!=(const setRBTIterator& op) const
{
	return (_startNode != op._startNode);
}

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::const_setRBTIterator synopsis
//--------------------------------------------------------------

template <class node, class Compare>
class const_setRBTIterator : public ft::iterator<ft::bidirectional_iterator_tag, node>
{
	public:
	// member types
	typedef typename node::value_type																value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
	typedef value_type* pointer;
	typedef value_type reference;

	public:
	// constructor
	const_setRBTIterator(const Compare& comp = Compare());
	// const_setRBTIterator(node* startNode, const Compare& comp = Compare());
	const_setRBTIterator(node* startNode, node* leafNode, const Compare& comp = Compare());
	const_setRBTIterator(const const_setRBTIterator& it);
	const_setRBTIterator(const setRBTIterator<node, Compare>& it);

	// destructor
	~const_setRBTIterator();

	// operator overloading
	const_setRBTIterator&	operator=(const const_setRBTIterator& it);
	const_setRBTIterator&	operator=(const setRBTIterator<ft::RBTNode<const typename node::value_type>, Compare>& it);
	const reference			operator*(void) const;
	pointer				operator->(void) const;
	const_setRBTIterator&	operator++(void);
	const_setRBTIterator	operator++(int);
	const_setRBTIterator&	operator--(void);
	const_setRBTIterator	operator--(int);
	bool				operator==(const const_setRBTIterator& op) const;
	bool				operator!=(const const_setRBTIterator& op) const;

	// private:
	// member variable
	node*		_startNode;
	node*		_leafNode;
	Compare			_comp;
};

//--------------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::const_setRBTIterator definition
//--------------------------------------------------------------

template <class node, class Compare>
const_setRBTIterator<node, Compare>::const_setRBTIterator(const Compare& comp) :
	_startNode(),
	_leafNode(),
	_comp(comp)
{}

template <class node, class Compare>
const_setRBTIterator<node, Compare>::const_setRBTIterator(node* newNode, node* leafNode, const Compare& comp) :
	_comp(comp)
{
	_startNode = newNode;
	_leafNode = leafNode;
}

template <class node, class Compare>
const_setRBTIterator<node, Compare>::const_setRBTIterator(const const_setRBTIterator& it) :
	_comp(it._comp)
{
	_startNode = it._startNode;
	_leafNode = it._leafNode;
}

template <class node, class Compare>
const_setRBTIterator<node, Compare>::const_setRBTIterator(const setRBTIterator<node, Compare>& it) :
	_comp(it._comp)
{
	_startNode = it._startNode;
	_leafNode = it._leafNode;
}

template <class node, class Compare>
const_setRBTIterator<node, Compare>::~const_setRBTIterator()
{}

template <class node, class Compare>
const_setRBTIterator<node, Compare>&
const_setRBTIterator<node, Compare>::operator=(const const_setRBTIterator &it)
{
	if (this == &it)
		return (*this);
	_startNode = it._startNode;
	_comp = it._comp;
	_leafNode = it._leafNode;
	return (*this);
}

template <class node, class Compare>
const typename const_setRBTIterator<node, Compare>::reference
const_setRBTIterator<node, Compare>::operator*(void) const
{
	const typename node::value_type	val = _startNode->_value;
	return (val);
}


template <class node, class Compare>
typename const_setRBTIterator<node, Compare>::pointer
const_setRBTIterator<node, Compare>::operator->(void) const
{
	if (_startNode == _leafNode)
		return (NULL);
	return (&(_startNode->_value));
}


template <class node, class Compare>
const_setRBTIterator<node, Compare>&
const_setRBTIterator<node, Compare>::operator++(void)
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
		while (curNode != _leafNode && _comp(curNode->_value, _startNode->_value))
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
const_setRBTIterator<node, Compare>
const_setRBTIterator<node, Compare>::operator++(int)
{
	const_setRBTIterator tmp(*this);
	operator++();
	return (tmp);
}

template <class node, class Compare>
const_setRBTIterator<node, Compare>&
const_setRBTIterator<node, Compare>::operator--(void)
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
		while (curNode != _leafNode && _comp(_startNode->_value, curNode->_value))
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
const_setRBTIterator<node, Compare>
const_setRBTIterator<node, Compare>::operator--(int)
{
	const_setRBTIterator tmp(*this);
	operator--();
	return (tmp);
}

template <class node, class Compare>
bool
const_setRBTIterator<node, Compare>::operator==(const const_setRBTIterator& op) const
{
	return (_startNode == op._startNode);
}

template <class node, class Compare>
bool
const_setRBTIterator<node, Compare>::operator!=(const const_setRBTIterator& op) const
{
	return (_startNode != op._startNode);
}

}
#endif
