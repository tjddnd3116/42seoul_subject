#ifndef set_hpp
#define set_hpp

#include "../utils/funtional.hpp"
#include "../iterator/reverseIterator.hpp"
#include "../utils/algorithm.hpp"
#include "../redBlackTree/setRedBlackTree.hpp"
#include <memory>
#include <type_traits>
#include <set>

namespace ft
{

//---------------------------------------
//   set<T, Compare, Alloc> synopsis
//---------------------------------------

template< class T,
		class Compare = ft::less<T>,
		class Alloc = std::allocator<T> >
class set
{
	// Member types
	public:
	typedef T																key_type;
	typedef key_type														value_type;
	typedef Compare															key_compare;
	typedef Compare 														value_compare;
	typedef Alloc 															allocator_type;
	typedef typename allocator_type::reference								reference;
	typedef typename allocator_type::const_reference						const_reference;
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer							const_pointer;
	typedef typename ft::setRedBlackTree<value_type, Compare, Alloc>::iterator			iterator;
	// typedef typename ft::setRedBlackTree<value_type, Compare, Alloc>::const_iterator	const_iterator;
	typedef typename ft::setRedBlackTree<value_type, Compare, Alloc>::iterator	const_iterator;
	typedef ft::reverse_iterator<iterator>									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
	typedef typename allocator_type::size_type								size_type;

	public:
	// constructor
	explicit	set(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
	template <class InputIterator>
				set(InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type(),
						typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0);
				set(const set& x);

	// operator
	set			&operator=(const set& x);

	// destructor
				~set();

	// Iterators
	iterator					begin();
	const_iterator				begin() const;
	iterator					end();
	const_iterator				end() const;
	reverse_iterator			rbegin();
	const_reverse_iterator		rbegin() const;
	reverse_iterator			rend();
	const_reverse_iterator		rend() const;

	// Capacity
	bool						empty() const;
	size_type					size() const;
	size_type					max_size() const;

	// Modifiers
	pair<iterator, bool>		insert(const value_type& val);
	iterator					insert(iterator position, const value_type& val);
	template <class InputIterator>
	void						insert(InputIterator first, InputIterator last,
			typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0);
	void						erase(iterator position);
	size_type					erase(const value_type& k);
	void						erase(iterator first, iterator last);
	void						swap(set& x);
	void						clear();

	// Observers
	key_compare					key_comp() const;
	value_compare				value_comp() const;

	// Operators
	iterator					find(const value_type& val) const;
	size_type					count(const value_type& val) const;
	iterator					lower_bound(const value_type& val) const;
	iterator					upper_bound(const value_type& val) const;
	pair<iterator, iterator>	equal_range(const value_type& val) const;

	// Allocator
	allocator_type				get_allocator() const;

	private:
	// member variable
	setRedBlackTree<value_type, Compare, Alloc>			_rbt;
	allocator_type										_alloc;
	Compare												_comp;
};

//---------------------------------------
//   set<T, Compare, Alloc> definition
//---------------------------------------

template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc) : _rbt(), _alloc(alloc), _comp(comp)
{
}

template <class T, class Compare, class Alloc>
template <class InputIterator>
set<T, Compare, Alloc>::set(InputIterator first, InputIterator last,
		const key_compare& comp, const allocator_type& alloc,
		typename std::enable_if<!std::is_integral<InputIterator>::value>::type*) : _rbt(), _alloc(alloc), _comp(comp)
{
	insert(first, last);
}

template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>::set(const set& x) : _rbt(), _alloc(x._alloc), _comp(x._comp)
{
	*this = x;
}


template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>&
set<T, Compare, Alloc>::operator=(const set& x)
{
	if (this == &x)
		return (*this);
	if (*this == x)
		return (*this);
	this->clear();
	this->insert(x.begin(), x.end());
	return (*this);
}

template <class T, class Compare, class Alloc>
set<T, Compare, Alloc>::~set()
{}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::begin()
{
	return (_rbt.begin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::begin() const
{
	return (_rbt.begin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::end()
{
	return (_rbt.end());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::end() const
{
	return (_rbt.end());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::reverse_iterator
set<T, Compare, Alloc>::rbegin()
{
	return (_rbt.rbegin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_reverse_iterator
set<T, Compare, Alloc>::rbegin() const
{
	return (_rbt.rbegin());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::reverse_iterator
set<T, Compare, Alloc>::rend()
{
	return (_rbt.rend());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_reverse_iterator
set<T, Compare, Alloc>::rend() const
{
	return (_rbt.rend());
}

template <class T, class Compare, class Alloc>
bool
set<T, Compare, Alloc>::empty() const
{
	return (_rbt.empty());
}


template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::size() const
{
	return (_rbt.size());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::max_size() const
{
	return (_rbt.max_size());
}


template <class T, class Compare, class Alloc>
pair<typename set<T, Compare, Alloc>::iterator, bool>
set<T, Compare, Alloc>::insert(const value_type& val)
{
	return (_rbt.insert(val));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return (_rbt.insert(val).first);
}

template <class T, class Compare, class Alloc>
template <class InputIterator>
void
set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last,
		typename std::enable_if<!std::is_integral<InputIterator>::value>::type*)
{
	for (; first != last; first++)
		_rbt.insert(*first);
}

template <class T, class Compare, class Alloc>
void
set<T, Compare, Alloc>::erase(iterator position)
{
	_rbt.erase(*position);
}


template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::erase(const value_type& k)
{
	size_type retSize;

	retSize = _rbt.erase(k);
	return (retSize);
}

template <class T, class Compare, class Alloc>
void
set<T, Compare, Alloc>::erase(iterator first, iterator last)
{
	iterator tmpIt = first++;
	while (tmpIt != last)
	{
		_rbt.erase(*tmpIt);
		tmpIt = first++;
	}
}


template <class T, class Compare, class Alloc>
void
set<T, Compare, Alloc>::swap(set& x)
{
	_rbt.swap(x._rbt);
}


template <class T, class Compare, class Alloc>
void
set<T, Compare, Alloc>::clear()
{
	_rbt.clear();
}


template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::key_compare
set<T, Compare, Alloc>::key_comp() const
{
	return (key_compare());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::value_compare
set<T, Compare, Alloc>::value_comp() const
{
	return (value_compare(key_compare()));
}


template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::find(const value_type& val) const
{
	return (_rbt.find(val));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::count(const value_type& val) const
{
	const_iterator findIt;

	findIt = _rbt.find(val);
	if (this->end() == findIt)
		return (0);
	return (1);
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::lower_bound(const value_type& val) const
{
	const_iterator beginIt;
	const_iterator endIt;

	beginIt = _rbt.begin();
	endIt = _rbt.end();
	while (beginIt != endIt && _comp(*beginIt, val))
		beginIt++;
	return (iterator(beginIt._startNode, beginIt._leafNode, beginIt._comp));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::upper_bound(const value_type& val) const
{
	const_iterator beginIt;
	const_iterator endIt;

	beginIt = _rbt.begin();
	endIt = _rbt.end();
	while (beginIt != endIt && !_comp(val, *beginIt))
		++beginIt;
	return (iterator(beginIt._startNode, beginIt._leafNode, beginIt._comp));
}

template <class T, class Compare, class Alloc>
pair<typename set<T, Compare, Alloc>::iterator, typename set<T, Compare, Alloc>::iterator>
set<T, Compare, Alloc>::equal_range(const value_type& val) const
{
	iterator lowerIt;
	iterator upperIt;

	lowerIt = this->lower_bound(val);
	upperIt = this->upper_bound(val);
	return (ft::make_pair(lowerIt, upperIt));
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::allocator_type
set<T, Compare, Alloc>::get_allocator() const
{
	return (_alloc);
}

template < class T, class Compare, class Alloc>
bool
operator==(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{
	if (&lhs == &rhs)
		return (true);
	if (lhs.size() != rhs.size())
		return (false);
	typename set<T, Compare, Alloc>::const_iterator lBegin = lhs.begin();
	typename set<T, Compare, Alloc>::const_iterator lEnd = lhs.end();
	typename set<T, Compare, Alloc>::const_iterator rBegin = rhs.begin();
	for (;lBegin != lEnd; ++lBegin, ++rBegin)
		if (*lBegin != *rBegin)
			return (false);
	return (true);
}

template < class T, class Compare, class Alloc>
bool
operator!=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template < class T, class Compare, class Alloc>
bool
operator<(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template < class T, class Compare, class Alloc>
bool
operator<=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template < class T, class Compare, class Alloc>
bool
operator>(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template < class T, class Compare, class Alloc>
bool
operator>=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

}
#endif
