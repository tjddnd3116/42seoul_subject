/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:17:37 by soum              #+#    #+#             */
/*   Updated: 2022/08/07 21:36:14 by soum             ###   ########.fr       */
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
//
// Red-Black Tree 의 정의
//
// 1. 각 노드의 색은 red 또는 black이다.
// 2. root 노드는 black이다.
// 3. 모든 말단노드(leaf node)는 black이다.
// 4. red 노드의 자식노드들은 전부 black이다.(red 노드는 연속되어 등장할 수 없다.)
// 5. root 노드에서 시작해서 말단노드에 이르는 모든 경로에는 동일한 개수의 black노드가 존재한다.

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
	node*					_tempNode;
	node_alloc				_nodeAlloc;
	Compare					_comp;
	size_type				_size;

	// member function
	void					treePrint(node *root, std::string indent, bool last);
	void					insertFixUp(node* newNode);
	void					rotateRight(node* rotateNode, node* rootNode);
	void					rotateLeft(node* rotateNode, node* rootNode);
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

	_tempNode = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(_tempNode, node(_leafNode, _leafNode, _leafNode));
	_tempNode->_color = BLACK;
	_size = 0;
}

template <class T, class Compare, class Alloc, class node>
redBlackTree<T, Compare, Alloc, node>::~redBlackTree()
{
	this->clear();
	_nodeAlloc.destroy(_leafNode);
	_nodeAlloc.deallocate(_leafNode, 1);
	_nodeAlloc.destroy(_tempNode);
	_nodeAlloc.deallocate(_tempNode, 1);
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
	return (reverse_iterator(end()));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rbegin() const
{
	return (const_reverse_iterator(end()));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rend()
{
	return (reverse_iterator(begin()));
}

template <class T, class Compare, class Alloc, class node>
typename redBlackTree<T, Compare, Alloc, node>::const_reverse_iterator
redBlackTree<T, Compare, Alloc, node>::rend() const
{
	return (const_reverse_iterator(begin()));
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
	Color eraseNodeColor;
	node* minNode;

	eraseNodeColor = eraseNode->_color;
	if (eraseNode->_left == _leafNode && eraseNode->_right == _leafNode)
	{
		childNode = _tempNode;
		moveChildToParent(eraseNode, childNode);
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
		if (childNode == _leafNode)
			childNode = _tempNode;
		if (minNode->_parent == eraseNode)
			childNode->_parent = minNode;
		else
		{
			moveChildToParent(minNode, childNode == _tempNode ? childNode : minNode->_right);
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
	else if (childNode == _tempNode)
	{
		if (childNode == childNode->_parent->_left)
			childNode->_parent->_left = _leafNode;
		else
			childNode->_parent->_right = _leafNode;
	}
	// treePrint(_leafNode->_parent, "", true);
	--_size;
	return (1);
}

// insert 문제 해결 방법
// - 문제 발생 경우
// 	1. 조건 2 위반
// 		기준노드가 red color 이면서 root 노드이다.
// 		-> 기준노드를 black color로 바꿔준다.
//
// 	2. 조건 4 위반
// 		기준노드와 부모노드둘다 red 이다.
// 		-> case 1. 기준노드의 삼촌노드가 red인경우
// 			기준노드의 부모노드와 삼촌노드를 black으로 바꿔주고 할아버지노드를 red로 바꿔준다.
// 			하지만 red-red 문제가 위로 2칸 이동해 있을수 있다.
// 			그러면 기준 노드를 할아버지 노드로 변경해 재귀적으로 문제를 해결한다.
//
// 		-> case 2. 기준노드의 삼촌 uncle이 black인 경우(leafNode 포함)
// 			-> case 2-1. 부모노드가 할아버지노드의 왼쪽 자식일경우
// 				-> case 2-1-1. 기준노드가 오른쪽 자식일경우
// 					부모노드를 left-rotation 한뒤 기준노드를 부모노드로 바꿔준다. -> case 2-1-2 상황으로 만듬
// 					그다음 case 2-1-2를 진행한다.
//
// 				-> case 2-1-2. 기준노드가 왼쪽 자식일경우
//					부모노드를 black, 할아버지노드를 red로 바꾼다. 할아버지노드를 기준으로 right-rotation을 진행한다.
//
//			-> case 2-2. 부모노드가 할아버지노드의 오른쪽 자식일 경우
//				-> case 2-2-1. 기준노드가 왼쪽 자식일경우
//					부모노드를 right-rotation 한뒤 기준노드를 부모노드로 바꿔준다. -> case 2-2-2 상황으로 만듬
//					그다음 case 2-2-2를 진행한다.
//				-> case 2-2-2.
//					부모노드를 black, 할아버지노드를 red로 바꾼다. 할아버지노드를 기준으로 left-rotation을 진행한다.
//
//	- 문제 종료 조건
//		기준노드가 black이면 종료한다.
// 
template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::insertFixUp(node* newNode)
{
	node* tempNode;

	tempNode = newNode;
	while (tempNode != _leafNode->_parent && tempNode->_parent->_color == RED) // 조건 4위반
	{
		node*	grandparent;
		node*	uncle;

		grandparent = tempNode->_parent->_parent;
		uncle = (tempNode->_parent == grandparent->_left) ? grandparent->_right : grandparent->_left;
		if (uncle != _leafNode && uncle->_color == RED)	// case 1
		{
			tempNode->_parent->_color = BLACK;
			uncle->_color = BLACK;
			grandparent->_color = RED;
			tempNode = grandparent;
		}
		else	// case 2
		{
			if (tempNode->_parent == grandparent->_left)	// case 2-1
			{
				if (tempNode == tempNode->_parent->_right) // case 2-1-1
				{
					tempNode = tempNode->_parent;
					rotateLeft(tempNode);
				}
				tempNode->_parent->_color = BLACK;			// case 2-1-2
				grandparent->_color = RED;
				rotateRight(grandparent);
			}
			else if (tempNode->_parent == grandparent->_right) // case 2-2
			{
				if (tempNode == tempNode->_parent->_left)	// case 2-2-1
				{
					tempNode = tempNode->_parent;
					rotateRight(tempNode);
				}
				tempNode->_parent->_color = BLACK;			// case 2-2-2
				grandparent->_color = RED;
				rotateLeft(grandparent);
			}
		}
	}
	_leafNode->_parent->_color = BLACK; // 조건 2해결
}


template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::rotateRight(node* rotateNode, node* rootNode)
{
	node* tempNode;

	tempNode = rotateNode->_left;
	rotateNode->_left = tempNode->_right;
	if (tempNode->_right != _leafNode)
		tempNode->_right->_parent = rotateNode;
	tempNode->_parent = rotateNode->_parent;
	if (rotateNode->_parent == _leafNode)
		rootNode = tempNode;
	else if (rotateNode == rotateNode->_parent->_left)
		rotateNode->_parent->_left = tempNode;
	else
		rotateNode->_parent->_right = tempNode;
	rotateNode->_parent = tempNode;
	tempNode->_right = rotateNode;
}

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::rotateLeft(node* rotateNode, node* rootNode)
{
	node* tempNode;

	tempNode = rotateNode->_right;
	rotateNode->_right = tempNode->_left;
	if (tempNode->_left != _leafNode)
		tempNode->_left->_parent = rotateNode;
	tempNode->_parent = rotateNode->_parent;
	if (rotateNode->_parent == _leafNode)
		rootNode = tempNode;
	else if (rotateNode == rotateNode->_parent->_left)
		rotateNode->_parent->_left = tempNode;
	else
		rotateNode->_parent->_right = tempNode;
	rotateNode->_parent = tempNode;
	tempNode->_left = rotateNode;
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
	if (parent->_parent == _leafNode && child == _tempNode)
		_leafNode->_parent = _leafNode;
	else if (parent->_parent == _leafNode)
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

//	erase 문제 해결 방법
//	1. 삭제한 노드가 red color 이다
//		->	red 노드의 자식과 부모는 black일것이므로 red를 지워도 black-black 연속은 문제 되지 않는다.
//
//	2. 삭제한 노드가 black color 이다.
//		->	조건4 위반
//				기준노드와 부모노드가 red color 이다.
//
//		->	조건5 위반
//			root 노드에서 leaf노드 까지의 black노드의 개수가 다름
//			-> case 1. 기준노드가 부모의 왼쪽 자식이다.
//				-> case 1-1. 형제노드가 red color 이다.
//					형제노드를 black로 부모노드를 red로 변경한뒤 부모노드기준으로 left-rotation을 진행한다.
//					이후 case 1-2, 1-3, 1-4로 진행한다.
//
//				-> case 1-2. 형제노드가 black, 형제노드의 자식들도 black이다.
//					형제노드를 red로 바꾼뒤 부모노드를 기준노드로 바꾼다.
//
//				-> case 1-3. 형제노드가 black, 형제노드의 왼쪽 자식이 red이다.
//					형제노드를 red로 바꾼뒤 형제노드의 왼쪽자식을 black으로 변경한다.
//					형제노드를 기준으로 right-rotate를 적용한다.
//					기준노트의 새로운 형제노드의 오른쪽 자식이 red이다. -> case 1-4에 해당하는 상황
//				-> case 1-4. 형제노드가 black, 형제노드의 오른쪽 자식이 red이다.
//					부모노드와 형제노드의 색을 바꾼뒤 형제노드의 오른쪽 자식을 black으로 바꾼다.
//					부모노드를 기준으로 left-rotation을 적용한다.
//			-> case 2. 기준노드가 부모의 오른쪽 자식이다.
//				-> case 2-1.
//
//				-> case 2-2.
//
//				-> case 2-3.
//
//				-> case 2-4.

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::eraseFixUp(node* childNode)
{
	node* siblingNode;
	node* tmpChildNode;

	tmpChildNode = childNode;
	while (tmpChildNode != _leafNode->_parent && tmpChildNode->_color == BLACK)
	{
		if (tmpChildNode == tmpChildNode->_parent->_left)	// case 1
		{
			siblingNode = tmpChildNode->_parent->_right;
			if (siblingNode->_color == RED)	// case 1-1
			{
				siblingNode->_color = BLACK;
				tmpChildNode->_parent->_color = RED;
				rotateLeft(tmpChildNode->_parent);
				siblingNode = tmpChildNode->_parent->_right;
			}
			if (siblingNode->_left->_color == BLACK && siblingNode->_right->_color == BLACK) // case 1-2
			{
				if (siblingNode != _leafNode)
					siblingNode->_color = RED;
				if (tmpChildNode == _tempNode)
				{
					if (tmpChildNode == tmpChildNode->_parent->_left)
						tmpChildNode->_parent->_left = _leafNode;
					else
						tmpChildNode->_parent->_right = _leafNode;
				}
				tmpChildNode = tmpChildNode->_parent;
			}
			else
			{
				if (siblingNode->_right->_color == BLACK)	// case1-3
				{
					siblingNode->_left->_color = BLACK;
					siblingNode->_color = RED;
					rotateRight(siblingNode);
					siblingNode = tmpChildNode->_parent->_right;
				}
				siblingNode->_color = tmpChildNode->_parent->_color; // case 1-4
				tmpChildNode->_parent->_color = BLACK;
				siblingNode->_right->_color = BLACK;
				rotateLeft(tmpChildNode->_parent);
				if (tmpChildNode == _tempNode)
				{
					if (tmpChildNode == tmpChildNode->_parent->_left)
						tmpChildNode->_parent->_left = _leafNode;
					else
						tmpChildNode->_parent->_right = _leafNode;
				}
				tmpChildNode = _leafNode->_parent;
			}
		}
		else											// case 2
		{
			siblingNode = tmpChildNode->_parent->_left;
			if (siblingNode->_color == RED)				// case 2-1
			{
				siblingNode->_color = BLACK;
				tmpChildNode->_parent->_color = RED;
				rotateRight(tmpChildNode->_parent);
				siblingNode = tmpChildNode->_parent->_left;
			}
			if (siblingNode->_left->_color == BLACK && siblingNode->_right->_color == BLACK) // case 2-2
			{
				if (siblingNode != _leafNode)
					siblingNode->_color = RED;
				if (tmpChildNode == _tempNode)
				{
					if (tmpChildNode == tmpChildNode->_parent->_left)
						tmpChildNode->_parent->_left = _leafNode;
					else
						tmpChildNode->_parent->_right = _leafNode;
				}
				tmpChildNode = tmpChildNode->_parent;
			}
			else
			{
				if (siblingNode->_left->_color == BLACK)			// case 2-3
				{
					siblingNode->_right->_color = BLACK;
					siblingNode->_color = RED;
					rotateLeft(siblingNode);
					siblingNode = tmpChildNode->_parent->_left;
				}
				siblingNode->_color = tmpChildNode->_parent->_color; // case 2-4
				tmpChildNode->_parent->_color = BLACK;
				siblingNode->_left->_color = BLACK;
				rotateRight(tmpChildNode->_parent);
				if (tmpChildNode == _tempNode)
				{
					if (tmpChildNode == tmpChildNode->_parent->_left)
						tmpChildNode->_parent->_left = _leafNode;
					else
						tmpChildNode->_parent->_right = _leafNode;
				}
				tmpChildNode = _leafNode->_parent;
			}
		}
	}
	tmpChildNode->_color = BLACK;
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
