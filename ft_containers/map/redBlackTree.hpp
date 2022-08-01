#ifndef redBlackTree_hpp
#define redBlackTree_hpp

#include <memory>
#include <string>
#include <iostream>
#include "../utils/funtional.hpp"
#include "../utils/utility.hpp"
#include "../iterator/reverseIterator.hpp"
#include "./RBTIterator.hpp"
#include "./RBTNode.hpp"

namespace ft
{

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc> synopsis
//------------------------------------------------------

template <class T,
		 class Compare = ft::less<T>,
		 class Alloc = std::allocator<T>,
		 class node = ft::RBTNode<T> >
class redBlackTree
{
	public:
	// member types
	typedef T												value_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;
	typedef std::allocator<node>							node_alloc;
	typedef	ft::RBTIterator<node, Compare>					iterator;
	typedef	ft::const_RBTIterator<node, Compare>			const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef size_t											size_type;


	public:
	// constructor
	redBlackTree(const allocator_type& alloc = allocator_type(),	// default constructor
			const Compare& comp = Compare());
	template<class InputIterator>
	redBlackTree(InputIterator first, InputIterator last);			// range constructor
	redBlackTree(const redBlackTree& rbt);							// copy constructor

	// operator
	redBlackTree			&operator=(const redBlackTree rbt);

	// destructor
	~redBlackTree();

	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	bool					empty() const;
	size_type				size() const;
	size_type				max_size() const;

	pair<iterator, bool>	insert(const value_type& val);
	iterator				find(const	typename value_type::first_type& key) const;

	private:
	// member variable
	node					*_leafNode;
	node_alloc				_nodeAlloc;
	Compare					_comp;
	size_type				_size;

	// member function
	void					inorderPrint(node *root);
	void					insertFixUp(node* newNode);
	void					rotateRight(node* rotateNode);
	void					rotateLeft(node* rotateNode);
};

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc> definition
//------------------------------------------------------

template <class T, class Compare, class Alloc, class node>
redBlackTree<T, Compare, Alloc, node>::redBlackTree(const allocator_type& alloc , const Compare& comp) : _nodeAlloc(alloc), _comp(comp)
{
	_leafNode = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(_leafNode, node(_leafNode, _leafNode, _leafNode));
	_leafNode->_color = BLACK;
	_size = 0;
}

// template <class Key, class T, class Compare, class Alloc>
// template <class InputIterator>
// redBlackTree<Key, T, Compare, Alloc>::redBlackTree(InputIterator first, InputIterator last)
// {
//
// }
//
// template <class Key, class T, class Compare, class Alloc>
// redBlackTree<Key, T, Compare, Alloc>::redBlackTree(const redBlackTree& rbt)
// {
//
// }


template <class T, class Compare, class Alloc, class node>
redBlackTree<T, Compare, Alloc, node>::~redBlackTree()
{}


template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::iterator
redBlackTree<T, Compare, Alloc, node>::begin()
{
	return (iterator(_leafNode->_parent));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_iterator
redBlackTree<T, Compare, Alloc, node>::begin() const
{
	return (const_iterator(_leafNode->_parent));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::iterator
redBlackTree<T, Compare, Alloc, node>::end()
{
	return (iterator(_leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_iterator
redBlackTree<T, Compare, Alloc, node>::end() const
{
	return (const_iterator(_leafNode));
}

// template <class T, class Compare, class Alloc, class node>
// typename redBlackTree<T, Compare, Alloc, node>::revese_iterator
// redBlackTree<T, Compare, Alloc, node>::rbegin()
// {
//
// }
//
// template <class T, class Compare, class Alloc, class node>
// typename redBlackTree<T, Compare, Alloc, node>::const_reverse_iterator
// redBlackTree<T, Compare, Alloc, node>::rbegin() const
// {
//
// }

// template <class T, class Compare, class Alloc, class node>
// typename redBlackTree<T, Compare, Alloc, node>::reverse_iterator
// redBlackTree<T, Compare, Alloc, node>::rend()
// {
//     return (reverse_iterator(_leafNode));
// }

// template <class T, class Compare, class Alloc, class node>
// typename redBlackTree<T, Compare, Alloc, node>::const_reverse_iterator
// redBlackTree<T, Compare, Alloc, node>::rend() const
// {
//
// }

template <class T, class Compare, class Alloc, class node>
bool
redBlackTree<T, Compare, Alloc, node>::empty() const
{
	if (_leafNode->_parent != _leafNode)
		return (true);
	return (false);
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::size_type
redBlackTree<T, Compare, Alloc, node>::size() const
{
	return (_size);
}


template <class T, class Compare, class Alloc, class node>
pair<typename redBlackTree<T, Compare, Alloc, node>::iterator, bool>
redBlackTree<T, Compare, Alloc, node>::insert(const value_type &val)
{
	node*	curNode;
	node*	preNode;
	node*	newNode;

	preNode = _leafNode;
	curNode = _leafNode->_parent;
	while (curNode != _leafNode)
	{
		if (curNode->_value.first == val.first)
			return (ft::make_pair(iterator(curNode, _leafNode), false));
		preNode = curNode;
		if (_comp(curNode->_value.first, val.first))
			curNode = curNode->_right;
		else
			curNode = curNode->_left;
	}
	newNode = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(newNode, node(val, preNode, _leafNode, _leafNode));
	++_size;
	if (preNode == _leafNode)
		_leafNode->_parent = newNode;
	else if (_comp(preNode->_value.first, val.first))
		preNode->_right = newNode;
	else
		preNode->_left = newNode;

	if (newNode->_parent == _leafNode)
	{
		newNode->_color = BLACK;
		// inorderPrint(_leafNode->_parent);
		return (ft::make_pair(iterator(newNode, _leafNode), true));
	}
	if (newNode->_parent->_parent == _leafNode)
	{
		// inorderPrint(_leafNode->_parent);
		return (ft::make_pair(iterator(newNode, _leafNode), true));
	}
	insertFixUp(newNode);
	// inorderPrint(_leafNode->_parent);
	return (ft::make_pair(iterator(newNode, _leafNode), true));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::iterator
redBlackTree<T, Compare, Alloc, node>::find(const typename value_type::first_type &key) const
{
	node* rootNode;
	node* parentNode;

	rootNode = _leafNode->_parent;
	while (rootNode != _leafNode && rootNode->_value.first != key)
	{
		parentNode = rootNode;
		rootNode = _comp(parentNode->_value.first, key) ? parentNode->_right : parentNode->_left;
	}
	return (iterator(rootNode));
}


template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::insertFixUp(node* newNode)
{
	node* tempNode;

	tempNode = newNode;
	while (tempNode != _leafNode->_parent && tempNode->_parent->_color == RED)
	{
		node*	grandparent;
		node*	uncle;
		bool	side;

		grandparent = tempNode->_parent->_parent;
		uncle = (tempNode->_parent == grandparent->_left) ? grandparent->_right : grandparent->_left;
		side = (tempNode->_parent == grandparent->_left) ? true : false;

		if (uncle != _leafNode && uncle->_color == RED)
		{
			tempNode->_parent->_color = BLACK;
			uncle->_color = BLACK;
			grandparent->_color = RED;
			tempNode = grandparent;
		}
		else
		{
			if (tempNode == (side ? tempNode->_parent->_right : tempNode->_parent->_left))
			{
				tempNode = tempNode->_parent;
				side ? rotateLeft(tempNode) : rotateRight(tempNode);
			}
			tempNode->_parent->_color = BLACK;
			grandparent->_color = RED;
			side ? rotateRight(grandparent) : rotateLeft(grandparent);
		}
	}
	_leafNode->_parent->_color = BLACK;
}


template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::rotateRight(node* rotateNode)
{
	node* tempNode;

	tempNode = rotateNode->_left;
	rotateNode->_left = tempNode->_right;
	if (tempNode->_right != _leafNode)
		tempNode->_right->_parent = rotateNode;
	tempNode->_parent = rotateNode->_parent;
	if (rotateNode->_parent == _leafNode)
		_leafNode->_parent = tempNode;
	else if (rotateNode == rotateNode->_parent->_left)
		rotateNode->_parent->_left = tempNode;
	else
		rotateNode->_parent->_right = tempNode;
	rotateNode->_parent = tempNode;
	tempNode->_right = rotateNode;
}

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::rotateLeft(node* rotateNode)
{
	node* tempNode;

	tempNode = rotateNode->_right;
	rotateNode->_right = tempNode->_left;
	if (tempNode->_left != _leafNode)
		tempNode->_left->_parent = rotateNode;
	tempNode->_parent = rotateNode->_parent;
	if (rotateNode->_parent == _leafNode)
		_leafNode->_parent = tempNode;
	else if (rotateNode == rotateNode->_parent->_left)
		rotateNode->_parent->_left = tempNode;
	else
		rotateNode->_parent->_right = tempNode;
	rotateNode->_parent = tempNode;
	tempNode->_left = rotateNode;
}

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::inorderPrint(node* root)
{
	if (root == _leafNode)
		return ;
	inorderPrint(root->_left);
	std::cout << "key : "<< root->_value.first << std::endl;
	std::cout << "value : "<< root->_value.second << std::endl;
	std::cout << "color : " << (root->_color ? "BLACK" : "RED") << std::endl;
	inorderPrint(root->_right);
}

}
#endif
