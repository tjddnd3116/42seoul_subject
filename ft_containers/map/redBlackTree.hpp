/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:17:37 by soum              #+#    #+#             */
/*   Updated: 2022/08/03 10:20:05 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	redBlackTree(const allocator_type& alloc = allocator_type(),
			const Compare& comp = Compare());

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
	iterator				find(const	typename value_type::first_type& key);
	const_iterator			find(const	typename value_type::first_type& key) const;
	void					clear();
	size_type				erase(const typename value_type::first_type& key);

	private:
	// member variable
	node*					_leafNode;
	node_alloc				_nodeAlloc;
	Compare					_comp;
	size_type				_size;

	// member function
	void					treePrint(node *root, std::string indent, bool last);
	void					insertFixUp(node* newNode);
	void					rotateRight(node* rotateNode);
	void					rotateLeft(node* rotateNode);
	void					clear(node* curNode);
	node*					findByKey(const typename value_type::first_type& key);
	void					moveChildToParent(node* parent, node *child);
	node*					nodeMin(node* curNode);
	void					eraseFixUp(node* childNode);
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

template <class T, class Compare, class Alloc, class node>
redBlackTree<T, Compare, Alloc, node>::~redBlackTree()
{
	this->clear();
	_nodeAlloc.destroy(_leafNode);
	_nodeAlloc.deallocate(_leafNode, 1);
}


template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::iterator
redBlackTree<T, Compare, Alloc, node>::begin()
{
	node* beginNode;

	beginNode = _leafNode->_parent;
	while (beginNode->_left != _leafNode)
		beginNode = beginNode->_left;
	return (iterator(beginNode, _leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_iterator
redBlackTree<T, Compare, Alloc, node>::begin() const
{
	node* beginNode;

	beginNode = _leafNode->_parent;
	while (beginNode->_left != _leafNode)
		beginNode = beginNode->_left;
	return (const_iterator(beginNode, _leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::iterator
redBlackTree<T, Compare, Alloc, node>::end()
{
	return (iterator(_leafNode, _leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_iterator
redBlackTree<T, Compare, Alloc, node>::end() const
{
	return (const_iterator(_leafNode, _leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rbegin()
{
	return (reverse_iterator(_leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rbegin() const
{
	return (const_reverse_iterator(_leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rend()
{
	return (reverse_iterator(_leafNode->_parent));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rend() const
{
	return (const_reverse_iterator(_leafNode->_parent));
}

template <class T, class Compare, class Alloc, class node>
bool
redBlackTree<T, Compare, Alloc, node>::empty() const
{
	if (_leafNode->_parent != _leafNode)
		return (false);
	return (true);
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
		// treePrint(_leafNode->_parent, "", true);
		return (ft::make_pair(iterator(newNode, _leafNode), true));
	}
	if (newNode->_parent->_parent == _leafNode)
	{
		// treePrint(_leafNode->_parent, "", true);
		return (ft::make_pair(iterator(newNode, _leafNode), true));
	}
	insertFixUp(newNode);
	// treePrint(_leafNode->_parent, "", true);
	return (ft::make_pair(iterator(newNode, _leafNode), true));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::iterator
redBlackTree<T, Compare, Alloc, node>::find(const typename value_type::first_type &key)
{
	node* rootNode;
	node* parentNode;

	rootNode = _leafNode->_parent;
	while (rootNode != _leafNode && rootNode->_value.first != key)
	{
		parentNode = rootNode;
		rootNode = _comp(parentNode->_value.first, key) ? parentNode->_right : parentNode->_left;
	}
	return (iterator(rootNode, _leafNode));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_iterator
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
	return (const_iterator(rootNode, _leafNode));
}


template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::clear()
{
	node* rootNode;

	rootNode = _leafNode->_parent;
	if (rootNode == _leafNode)
		return;
	clear(rootNode);
	_leafNode->_parent = _leafNode;
	_size = 0;
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::size_type
redBlackTree<T, Compare, Alloc, node>::erase(const typename value_type::first_type &key)
{
	node* eraseNode;

	eraseNode = findByKey(key);
	if (eraseNode == _leafNode)
		return (0);
	node* childNode;
	Color eraseNodeColor = eraseNode->_color;
	node* minNode;
	if (eraseNode->_left == _leafNode && eraseNode->_right == _leafNode)
	{
		if (eraseNode->_parent == _leafNode)
			_leafNode->_parent = _leafNode;
		else if (eraseNode == eraseNode->_parent->_left)
			eraseNode->_parent->_left = _leafNode;
		else
			eraseNode->_parent->_right = _leafNode;
		// _nodeAlloc.destroy(eraseNode);
		// _nodeAlloc.deallocate(eraseNode, 1);
	}
	else if (eraseNode->_left == _leafNode)
	{
		childNode = eraseNode->_right;
		moveChildToParent(eraseNode, eraseNode->_right);
	}
	else if (eraseNode->_right == _leafNode)
	{
		childNode = eraseNode->_left;
		moveChildToParent(eraseNode, eraseNode->_left);
	}
	else
	{
		minNode = nodeMin(eraseNode->_right);
		eraseNodeColor = minNode->_color;
		childNode = minNode->_right;
		if (minNode->_parent == eraseNode)
			childNode->_parent = minNode;
		else
		{
			moveChildToParent(minNode, minNode->_right);
			minNode->_right = eraseNode->_right;
			minNode->_right->_parent = minNode;
		}
		moveChildToParent(eraseNode, minNode);
		minNode->_left = eraseNode->_left;
		minNode->_left->_parent = minNode;
		minNode->_color = eraseNode->_color;
	}
	_nodeAlloc.destroy(eraseNode);
	_nodeAlloc.deallocate(eraseNode, 1);
	if (eraseNodeColor == BLACK)
		eraseFixUp(childNode);
	treePrint(_leafNode->_parent, "", true);
	_size--;
	return (1);
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
redBlackTree<T, Compare, Alloc, node>::clear(node *curNode)
{
	if (curNode == _leafNode)
		return ;
	clear(curNode->_left);
	clear(curNode->_right);
	_nodeAlloc.destroy(curNode);
	_nodeAlloc.deallocate(curNode, 1);
}

template <class T, class Compare, class Alloc, class node>
node*
redBlackTree<T, Compare, Alloc, node>::findByKey(const typename value_type::first_type& key)
{
	node* rootNode;
	node* parentNode;

	rootNode = _leafNode->_parent;
	while (rootNode != _leafNode && rootNode->_value.first != key)
	{
		parentNode = rootNode;
		rootNode = _comp(parentNode->_value.first, key) ? parentNode->_right : parentNode->_left;
	}
	return (rootNode);
}


template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::moveChildToParent(node* parent, node* child)
{
	if (parent->_parent == _leafNode)
		_leafNode->_parent = child;
	else if (parent == parent->_parent->_left)
		parent->_parent->_left = child;
	else
		parent->_parent->_right = child;
	child->_parent = parent->_parent;
}

template <class T, class Compare, class Alloc, class node>
node*
redBlackTree<T, Compare, Alloc, node>::nodeMin(node* curNode)
{
	node* retNode;

	retNode = curNode;
	while (retNode->_left != _leafNode)
		retNode = retNode->_left;
	return (retNode);
}

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::eraseFixUp(node* childNode)
{
	node* siblingNode;

	while (childNode != _leafNode && childNode->_color == BLACK)
	{
		if (childNode == childNode->_parent->_left)
		{
			siblingNode = childNode->_parent->_right;
			if (siblingNode->_color == RED)
			{
				siblingNode->_color = BLACK;
				childNode->_parent->_color = RED;
				rotateLeft(childNode->_parent);
				siblingNode = childNode->_parent->_right;
			}
			if (siblingNode->_left->_color == BLACK && siblingNode->_right->_color == BLACK)
			{
				siblingNode->_color = RED;
				childNode = childNode->_parent;
			}
			else
			{
				if (siblingNode->_right->_color == BLACK)
				{
					siblingNode->_left->_color = BLACK;
					siblingNode->_color = RED;
					rotateRight(siblingNode);
					siblingNode = childNode->_parent->_right;
				}
				siblingNode->_color = childNode->_parent->_color;
				childNode->_parent->_color = BLACK;
				siblingNode->_right->_color = BLACK;
				rotateLeft(childNode->_parent);
				childNode = _leafNode->_parent;
			}
		}
		else
		{
			siblingNode = childNode->_parent->_left;
			if (siblingNode->_color == RED)
			{
				siblingNode->_color = BLACK;
				childNode->_parent->_color = RED;
				rotateRight(childNode->_parent);
				siblingNode = childNode->_parent->_left;
			}
			if (siblingNode->_left->_color == BLACK && siblingNode->_right->_color == BLACK)
			{
				siblingNode->_color = RED;
				childNode = childNode->_parent;
			}
			else
			{
				if (siblingNode->_left->_color == BLACK)
				{
					siblingNode->_right->_color = BLACK;
					siblingNode->_color = RED;
					rotateLeft(siblingNode);
					siblingNode = childNode->_parent->_left;
				}
				siblingNode->_color = childNode->_parent->_color;
				childNode->_parent->_color = BLACK;
				siblingNode->_left->_color = BLACK;
				rotateRight(childNode->_parent);
				childNode = _leafNode->_parent;
			}
		}
	}
	childNode->_color = BLACK;
	_leafNode->_parent->_color = BLACK;
}

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::treePrint(node* root, std::string indent, bool last)
{
	if (root == _leafNode)
		return ;
	std::cout << indent;
	if (last)
	{
		std::cout << "R----";
		indent += "    ";
	}
	else
	{
		std::cout << "L----";
		indent +="|    ";
	}
	std::cout << root->_value.first << (root->_color ? " BLACK" : " RED") << std::endl;
	treePrint(root->_left, indent, false);
	treePrint(root->_right, indent, true);
}

}
#endif
