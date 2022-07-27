#ifndef redBlackTree_hpp
#define redBlackTree_hpp

#include <memory>
#include <string>
#include <iostream>
#include "../utils/funtional.hpp"
#include "../utils/utility.hpp"
#include "../iterator/bidirectionalIterator.hpp"
#include "../iterator/reverseIterator.hpp"
#include "RBTIterator.hpp"

namespace ft
{

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc> synopsis
//------------------------------------------------------

template <class Key,
		 class T,
		 class Compare = ft::less<Key>,
		 class Alloc = std::allocator<ft::pair<const Key, T> > >
class redBlackTree
{
	private:
	// member types
	struct													node;

	public:

	typedef Key												key_type;
	typedef T												mapped_type;
	typedef ft::pair<const key_type, mapped_type>			value_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;
	typedef std::allocator<node>							node_alloc;
	typedef	ft::RBTIterator<node, Compare>					iterator;
	typedef	ft::const_RBTIterator<node, Compare>			const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef typename allocator_type::size_type				size_type;

	public:
	// constructor
	redBlackTree(const allocator_type& alloc = allocator_type());											// default constructor
	template<class InputIterator>
	redBlackTree(InputIterator first, InputIterator last);	// range constructor
	redBlackTree(const redBlackTree& rbt);					// copy constructor

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

	void					insert(const value_type& val);
	// pair<iterator, bool>	insert(const value_type& val);

	private:
	// member variable
	node			*_leafNode;
	node_alloc		_nodeAlloc;
};

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc> definition
//------------------------------------------------------


template <class Key, class T, class Compare, class Alloc>
redBlackTree<Key, T, Compare, Alloc>::redBlackTree(const allocator_type& alloc) : _nodeAlloc(alloc)
{
	_leafNode = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(_leafNode, node(_leafNode, _leafNode, _leafNode));
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


template <class Key, class T, class Compare, class Alloc>
redBlackTree<Key, T, Compare, Alloc>::~redBlackTree()
{}

template <class Key, class T, class Compare, class Alloc>
void
// pair<typename redBlackTree<Key, T, Compare, Alloc>::iterator, bool>
redBlackTree<Key, T, Compare, Alloc>::insert(const value_type &val)
{
	node*	curNode;
	node*	preNode;
	node*	newNode;

	preNode = _leafNode;
	curNode = _leafNode->_parent;
	while (curNode != _leafNode)
	{
		if (curNode->_value.first == val.first)
			return ;
			// return (ft::make_pair(iterator(curNode, _leafNode), false));
		preNode = curNode;
		if (curNode->_value.first < val.first)
			curNode = curNode->_right;
		else
			curNode = curNode->_left;
	}
	newNode = _nodeAlloc.allocate(1);
	_nodeAlloc.construct(newNode, node(val, preNode, _leafNode, _leafNode));
	if (preNode == _leafNode)
		_leafNode->_parent = newNode;
	else if (curNode->_value.first < val.first)
		preNode->_right = newNode;
	else
		preNode->_left = newNode;
	// return (ft::make_pair(iterator(newNode, _leafNode), true));
}

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::node synopsis
//------------------------------------------------------

template <class Key, class T, class Compare, class Alloc>
struct redBlackTree<Key, T, Compare, Alloc>::node
{
	std::string	_color;
	value_type	_value;
	node*		_parent;
	node*		_left;
	node*		_right;

	// constructor
	node(node* parent, node* left, node* right) :
		_value(),
		_parent(parent),
		_left(left),
		_right(right)
	{
		_color = "black";
	}
	node(const value_type& val, node* parent, node* left, node* right) :
		_value(val),
		_parent(parent),
		_left(left),
		_right(right)
	{
		_color = "black";
	}
	// destructor
	~node()
	{}

	void	setNodeColor(const std::string& color)
	{
		_color = color;
	}
};

}
#endif
