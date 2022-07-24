#ifndef redBlackTree_hpp
#define redBlackTree_hpp

#include <memory>
#include <string>
#include <iostream>
#include "../utils/funtional.hpp"
#include "../utils/utility.hpp"
#include "../iterator/bidirectionalIterator.hpp"

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
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef	ft::bidirectional_iterator<value_type>			iterator;
		typedef	ft::bidirectional_iterator<const value_type>	const_iterator;

	private:
	// member types
	struct											node;

	public:
	// constructor
	redBlackTree();											// default constructor
	template<class InputIterator>
	redBlackTree(InputIterator first, InputIterator last);	// range constructor
	redBlackTree(const redBlackTree& rbt);					// copy constructor

	// operator
	redBlackTree	&operator=(const redBlackTree rbt);

	// destructor
	~redBlackTree();

	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	// reverse_iterator		rbegin();
	// const_reverse_iterator	rbegin() const;
	// reverse_iterator		rend();
	// const_reverse_iterator	rend() const;

	bool					empty() const;
	// size_type				size() const;
	// size_type				max_size() const;

	void					insert(const value_type& val);
	// pair<iterator, bool>	insert(const value_type& val);
	private:
	// member variable
	node	*_root;
};

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc> definition
//------------------------------------------------------


template <class Key, class T, class Compare, class Alloc>
redBlackTree<Key, T, Compare, Alloc>::redBlackTree()
{
	_root = NULL;
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
// pair<typename redBlackTree<Key, T, Compare, Alloc>::iterator, bool>
void
redBlackTree<Key, T, Compare, Alloc>::insert(const value_type &val)
{
	if (!_root)
		_root = new node(val);
	else
	{
		node *newNode = NULL;
	}
}
//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc>::node synopsis
//------------------------------------------------------
template <class Key, class T, class Compare, class Alloc>
struct redBlackTree<Key, T, Compare, Alloc>::node
{
	std::string	_color;
	value_type	_value;
	// size_type	_height;
	node*		_parent;
	node*		_left;
	node*		_right;

	// constructor
	node() : _value()
	{
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	node(const value_type& val) : _value(val)
	{
		_color = "black";
		_parent = NULL;
		_left = NULL;
		_right = NULL;
	}
	// destructor
	~node()
	{}
};

}
#endif
