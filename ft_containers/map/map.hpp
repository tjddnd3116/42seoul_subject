#ifndef map_hpp
#define	map_hpp

#include <memory>
#include "../iterator/bidirectionalIterator.hpp"
#include "../iterator/reverseIterator.hpp"
namespace ft
{

//---------------------------------------
//   map<Key, T, Compare, Alloc> synopsis
//---------------------------------------

template <class Key,
		 class T,
		 class Compare = std::less<Key>,
		 class Alloc = std::allocator<std::pair<const Key, T> > >
class map
{
	public:
	// Member types
	typedef Key														key_type;
	typedef T														mapped_type;
	typedef std::pair<const key_type, mapped_type>					value_type;
	typedef Compare													key_compare;
//	typedef ???														value_compare
	typedef Alloc													allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef	ft::bidirectional_iterator<value_type>					iterator;
	typedef	ft::bidirectional_iterator<const value_type>			const_iterator;
	typedef ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::size_type						size_type;

	private:
};

//---------------------------------------
//   map<Key, T, Compare, Alloc> definition
//---------------------------------------

}

#endif
