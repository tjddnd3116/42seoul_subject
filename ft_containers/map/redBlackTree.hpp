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
			const Compare& comp = Compare());											// default constructor
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

	pair<iterator, bool>	insert(const value_type& val);

	private:
	// member variable
	node			*_leafNode;
	node_alloc		_nodeAlloc;
	Compare			_comp;
	// member function
	void		inorderPrint(node *root);
};

//------------------------------------------------------
//   redBlackTree<Key, T, Compare, Alloc> definition
//------------------------------------------------------

template <class T, class Compare, class Alloc, class node>
redBlackTree<T, Compare, Alloc, node>::redBlackTree(const allocator_type& alloc , const Compare& comp) : _nodeAlloc(alloc), _comp(comp)
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


template <class T, class Compare, class Alloc, class node>
redBlackTree<T, Compare, Alloc, node>::~redBlackTree()
{}

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
	if (preNode == _leafNode)
		_leafNode->_parent = newNode;
	else if (_comp(preNode->_value.first, val.first))
		preNode->_right = newNode;
	else
		preNode->_left = newNode;
	// this->inorderPrint(_leafNode->_parent);
	return (ft::make_pair(iterator(newNode, _leafNode), true));
}

template <class T, class Compare, class Alloc, class node>
void
redBlackTree<T, Compare, Alloc, node>::inorderPrint(node* root)
{
	if (root == _leafNode)
		return ;
	inorderPrint(root->_left);
	std::cout << root->_value.first << std::endl;
	std::cout << root->_value.second << std::endl;
	inorderPrint(root->_right);
}

}
#endif
