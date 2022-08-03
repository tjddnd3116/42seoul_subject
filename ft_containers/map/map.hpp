#ifndef map_hpp
#define	map_hpp

#include <memory>
#include <type_traits>
#include "../iterator/bidirectionalIterator.hpp"
#include "../iterator/reverseIterator.hpp"
#include "../utils/funtional.hpp"
#include "../utils/algorithm.hpp"
#include "../utils/utility.hpp"
#include "./redBlackTree.hpp"

namespace ft
{

//---------------------------------------
//   map<Key, T, Compare, Alloc> synopsis
//---------------------------------------

template <class Key,
		 class	T,
		 class	Compare = ft::less<Key>,
		 class	Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
	// Member types
	public:
	typedef Key															key_type;
	typedef T															mapped_type;
	typedef ft::pair<const key_type, mapped_type>						value_type;
	typedef Compare														key_compare;
	class																value_compare;
	typedef Alloc														allocator_type;
	typedef typename allocator_type::reference							reference;
	typedef typename allocator_type::const_reference					const_reference;
	typedef typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef	typename ft::redBlackTree<value_type, Compare, Alloc>::iterator		iterator;
	typedef	typename ft::redBlackTree<value_type, Compare, Alloc>::const_iterator	const_iterator;
	typedef ft::reverse_iterator<iterator>								reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
	typedef typename allocator_type::size_type							size_type;


	public:
	// constructor
	explicit	map(const key_compare& comp = key_compare(),											// default constructor (1)
			const allocator_type& alloc = allocator_type());
	template <class InputIterator>
				map(InputIterator first, InputIterator last,											// range constructor (2)
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type(),
						typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0);
				map(const map& x);																		// copy constructor (3)

	// operator
	map			&operator=(const map& x);

	// destructor
				~map();

	// Iterators
	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	//	Capacity
	bool					empty() const;
	size_type				size() const;
	size_type				max_size() const;

	// Element access
	mapped_type&			operator[](const key_type& k);

	// Modifiers
	// void					insert(const value_type& val);									// insert - single element (1)
	pair<iterator, bool>	insert(const value_type& val);									// insert - single element (1)
	iterator				insert(iterator position, const value_type& val);				// insert - with hint (2)
	template <class InputIterator>
	void					insert(InputIterator first, InputIterator last,					// insert - range (3)
			typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0);
	void					erase(iterator position);										// erase - position (1)
	size_type				erase(const key_type& k);										// erase - single element(2)
	void					erase(iterator first, iterator last);							// erase - range(3)
	void					swap(map& x);
	void					clear();

	// Observers
	key_compare				key_comp() const;
	value_compare			value_comp() const;

	// Operators
	iterator				find(const key_type& k);
	const_iterator			find(const key_type& k) const;
	size_type				count(const key_type& k) const;
	iterator				lower_bound(const key_type& k);
	const_iterator			lower_bound(const key_type& k) const;
	iterator				upper_bound(const key_type& k);
	const_iterator			upper_bound(const key_type& k) const;
	pair<iterator, iterator>				equal_range(const key_type& k);
	pair<const_iterator, const_iterator>	equal_range(const key_type& k)	const;

	// Allocator
	allocator_type			get_allocator() const;


	private:
	// member variable
	redBlackTree<value_type, Compare, Alloc>	_rbt;
	allocator_type								_alloc;
	Compare										_comp;

};

//---------------------------------------
//   map<Key, T, Compare, Alloc> definition
//---------------------------------------

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :_rbt(), _alloc(alloc), _comp(comp)
{}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last,
		const key_compare& comp, const allocator_type& alloc,
		typename std::enable_if<!std::is_integral<InputIterator>::value>::type*) : _rbt(), _alloc(alloc), _comp(comp)
{
	insert(first, last);
}

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(const map& x) :_rbt(), _alloc(x._alloc), _comp(x._comp)
{
	*this = x;
}


template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>&
map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	if (this == &x)
		return (*this);
	if (*this == x)
		return (*this);
	this->clear();
	this->insert(x.begin(), x.end());
	return (*this);
}


template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::~map()
{
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::begin()
{
	return (_rbt.begin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::begin() const
{
	return (_rbt.begin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::end()
{
	return (_rbt.end());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::end() const
{
	return (_rbt.end());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rbegin()
{
	return (_rbt.rbegin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rbegin() const
{
	return (_rbt.rbegin());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rend()
{
	return (_rbt.rend());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rend() const
{
	return (_rbt.rend());
}


template <class Key, class T, class Compare, class Alloc>
bool
map<Key, T, Compare, Alloc>::empty() const
{
	return (_rbt.empty());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::size() const
{
	return (_rbt.size());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::max_size() const
{
	return (_alloc.max_size());
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
	return (_rbt.insert(value_type(k, mapped_type())).first->second);
}

template <class Key, class T, class Compare, class Alloc>
// void
pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	return (_rbt.insert(val));
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return (_rbt.insert(val).first);
}


template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void
map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last,
		typename std::enable_if<!std::is_integral<InputIterator>::value>::type*)
{
	for (; first != last; first++)
		_rbt.insert(ft::make_pair(first->first, first->second));
}

// template <class Key, class T, class Compare, class Alloc>
// void
// map<Key, T, Compare, Alloc>::erase(iterator position)
// {
//     _rbt.erase(position->first);
// }

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	size_type retSize;

	retSize = _rbt.erase(k);
	return (retSize);
}

// template <class Key, class T, class Compare, class Alloc>
// void
// map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
// {
//     for (; first != last; first++)
//         erase(first);
// }


template <class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::swap(map& x)
{
	map tempMap;

	tempMap = x;
	x = *this;
	*this = tempMap;
}

template <class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::clear()
{
	_rbt.clear();
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::key_compare
map<Key, T, Compare, Alloc>::key_comp() const
{
	return (key_compare());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::value_compare
map<Key, T, Compare, Alloc>::value_comp() const
{
	return (value_compare(key_compare()));
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::find(const key_type& k)
{
	return (_rbt.find(k));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
	return (_rbt.find(k));
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	const_iterator findIt;

	findIt = _rbt.find(k);
	if (this->end() == findIt)
		return (0);
	return (1);
}


template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	iterator beginIt;
	iterator endIt;

	beginIt = _rbt.begin();
	endIt = _rbt.end();
	while (beginIt != endIt && _comp(beginIt->first, k))
		beginIt++;
	return (beginIt);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	const_iterator beginIt;
	const_iterator endIt;

	beginIt = _rbt.begin();
	endIt = _rbt.end();
	while (beginIt != endIt && _comp(beginIt->first, k))
		beginIt++;
	return (beginIt);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	iterator beginIt;
	iterator endIt;

	beginIt = _rbt.begin();
	endIt = _rbt.end();
	while (beginIt != endIt && !_comp(k, beginIt->first))
		beginIt++;
	return (beginIt);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	const_iterator beginIt;
	const_iterator endIt;

	beginIt = _rbt.begin();
	endIt = _rbt.end();
	while (beginIt != endIt && !_comp(k, beginIt->first))
		beginIt++;
	return (beginIt);
}

template <class Key, class T, class Compare, class Alloc>
pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	iterator lowerIt;
	iterator upperIt;

	lowerIt = this->lower_bound(k);
	upperIt = this->upper_bound(k);
	return (ft::make_pair(lowerIt, upperIt));
}

template <class Key, class T, class Compare, class Alloc>
pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	const_iterator lowerIt;
	const_iterator upperIt;

	lowerIt = this->lower_bound(k);
	upperIt = this->upper_bound(k);
	return (ft::make_pair(lowerIt, upperIt));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::allocator_type
map<Key, T, Compare, Alloc>::get_allocator() const
{
	return (_alloc);
}

//------------------------------------------------------
//   map<Key, T, Compare, Alloc>::value_compare synopsis
//------------------------------------------------------

template <class Key, class T, class Compare, class Alloc>
class map<Key, T, Compare, Alloc>::value_compare : public binary_funtion<value_type, value_type, bool>
{
	friend class map;

	public:
	// member functions
	bool	operator() (const value_type& x, const value_type& y) const
	{
		return (comp(x.first, y.first));
	}
	protected:
	// constructor
	value_compare(key_compare pr) : comp(pr)
	{}
	// member variable
	key_compare comp;
};

template <class Key, class T, class Compare, class Alloc>
bool
operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	if (&lhs == &rhs)
		return (true);
	if (lhs.size() != rhs.size())
		return (false);
	typename map<Key, T, Compare, Alloc>::const_iterator lBegin = lhs.begin();
	typename map<Key, T, Compare, Alloc>::const_iterator lEnd = lhs.end();
	typename map<Key, T, Compare, Alloc>::const_iterator rBegin = rhs.begin();
	for (;lBegin != lEnd; ++lBegin, ++rBegin)
		if (*lBegin != *rBegin)
			return (false);
	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool
operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool
operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool
operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool
operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool
operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

}
#endif
