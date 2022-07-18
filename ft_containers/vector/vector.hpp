#ifndef vector_hpp
#define vector_hpp

#include <memory>
#include <stdexcept>
#include <type_traits>
#include "../iterator/randomAccessIterator.hpp"
#include "../iterator/reverseIterator.hpp"
#include "../utils/typeTraits.hpp"

namespace	ft
{

//---------------------------------------
//   vector<T, Allocator> synopsis
//---------------------------------------

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
	//	Member types
	typedef T														value_type;
	typedef Allocator												allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef	ft::random_access_iterator<value_type>					iterator;
	typedef	ft::random_access_iterator<const value_type>			const_iterator;
	typedef ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::size_type						size_type;

	//	constructor
	explicit	vector(const allocator_type& alloc = allocator_type());		// default constructor (1)
	explicit	vector(size_type n,											// fill constructor (2)
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type());
	template <class InputIterator>
				vector(InputIterator first,									// range constructor (3)
						InputIterator last,
						const allocator_type& alloc = allocator_type(),
		typename enable_if<is_iterator<InputIterator>::value, InputIterator>::type = 0) ;
				vector(const vector& x);									// copy constructor (4)

	// operator
	vector		&operator=(const vector& x);								// copy assignment oeprator

	// destructor
				~vector();

	// Iterators
	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	// Capacity
	size_type				size() const;
	size_type				max_size() const;
	void					resize(size_type n, value_type val = value_type());
	size_type				capacity() const;
	bool					empty() const;
	void					reserve(size_type n);

	// Element access
	reference				operator[](size_type n);
	const_reference			operator[](size_type n) const;
	reference				at(size_type n);
	const_reference			at(size_type n) const;
	reference				front();
	const_reference			front() const;
	reference				back();
	const_reference			back() const;

	// Modifiers
	template <class InputIterator>
	void					assign(InputIterator first,						// range (1)
									InputIterator last);
	void					assign(size_type n,								// fill (2)
									const value_type& val = value_type());
	void					push_back(const value_type& val);
	void					pop_back();
	iterator				insert(iterator position,						// single element (1)
									const value_type& val = value_type());
	void					insert(iterator position, size_type n,			// fill (2)
									const value_type& val = value_type());
	template <class InputIterator>
	void					insert(iterator position,						// range (3)
									InputIterator first,
									InputIterator last);
	iterator				erase(iterator position);
	iterator				erase(iterator first, iterator last);
	void					swap(vector& x);
	void					clear();

	// Allocator
	allocator_type			get_allocator() const;

	private:
	// member variable
	pointer					_firstData;
	pointer					_lastData;
	pointer					_endData;
	allocator_type			_alloc;
};

//---------------------------------------
//   vector<T, Allocator> definition
//---------------------------------------

template <class T, class Allocator>
vector<T, Allocator>::vector(const allocator_type& alloc) : _alloc(alloc)
{
	_firstData = NULL;
	_lastData = NULL;
	_endData = NULL;
}

template <class T, class Allocator>
vector<T, Allocator>::vector(size_type n,
		const value_type& val,
		const allocator_type& alloc) : _alloc(alloc)
{
	_firstData = _alloc.allocate(n);
	_lastData = _firstData + n;
	_endData = _firstData + n;
	std::uninitialized_fill(_firstData, _lastData, val);
}

template <class T, class Allocator>
template<class InputIterator>
vector<T, Allocator>::vector(InputIterator first,
		InputIterator last,
		const allocator_type& alloc,
		typename enable_if<is_iterator<InputIterator>::value, InputIterator>::type) : _alloc(alloc)
{
	difference_type n = last - first;
	_firstData = _alloc.allocate(n);
	_lastData = _firstData;
	_endData = _firstData + n;
	while (n--)
	{
		_alloc.construct(_lastData, *(first++));
		_lastData++;
	}
}

template <class T, class Allocator>
vector<T, Allocator>::vector(const vector<T, Allocator>& x) : _alloc(x._alloc)
{
	_firstData = NULL;
	_lastData = NULL;
	_endData = NULL;
	*this = x;
}

template <class T, class Allocator>
vector<T, Allocator>&
vector<T, Allocator>::operator=(const vector<T, Allocator> &x)
{
	if (x == *this)
		return (*this);
	if (this->capacity() < x.size())
	{
		this->reserve(x.size());
		this->clear();
		std::uninitialized_copy(x._firstData, x._lastData, _firstData);
		_lastData = _firstData + x.size();
	}
	else
	{
		this->clear();
		std::uninitialized_copy(x._firstData, x._lastData, _firstData);
		_lastData = _firstData + x.size();
	}
	return (*this);
}


template <class T, class Allocator>
vector<T, Allocator>::~vector()
{
	this->clear();
	_alloc.deallocate(_firstData, this->capacity());
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::begin()
{
	return (iterator(_firstData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin() const
{
	return (const_iterator(_firstData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::end()
{
	return (iterator(_lastData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::end() const
{
	return (const_iterator(_lastData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rbegin()
{
	return (reverse_iterator(_lastData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rbegin() const
{
	return (const_reverse_iterator(_lastData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rend()
{
	return (reverse_iterator(_firstData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rend() const
{
	return (const_reverse_iterator(_firstData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::size() const
{
	return (_lastData - _firstData);
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::max_size() const
{
	return (_alloc.max_size());
}

template <class T, class Allocator>
void
vector<T, Allocator>::resize(size_type n, value_type val)
{
	if (n > this->max_size())
		throw (std::length_error("length_error"));
	if (this->size() > n)
	{
		while (this->size() > n)
			_alloc.destroy(--_lastData);
	}
	else if (this->size() < n)
	{
		if (this->capacity() < n)
		{
			pointer newFirstData;
			pointer newLastData;
			pointer	newEndData;
			size_type newSize;

			if (n > this->capacity() * 2)
				newSize = n;
			else
				newSize = this->capacity() * 2;
			newFirstData = _alloc.allocate(newSize);
			newEndData = newFirstData + newSize;
			std::uninitialized_copy(_firstData, _lastData, newFirstData);
			std::uninitialized_fill(newFirstData + this->size(), newFirstData + n, val);
			newLastData = newFirstData + n;
			this->clear();
			_alloc.deallocate(_firstData, this->capacity());
			_firstData = newFirstData;
			_lastData = newLastData;
			_endData = newEndData;
		}
		else
		{
			std::uninitialized_fill(_lastData, _firstData + n, val);
			_lastData = _firstData + n;
		}
	}
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::capacity() const
{
	return (_endData - _firstData);
}


template <class T, class Allocator>
bool
vector<T, Allocator>::empty() const
{
	return (this->size() ? false : true);
}

template <class T, class Allocator>
void
vector<T, Allocator>::reserve(size_type n)
{
	if (n > this->max_size())
		throw (std::length_error("length_error"));
	if (this->capacity() < n)
	{
		pointer newFirstData;
		pointer newLastData;
		pointer newEndData;

		newFirstData = _alloc.allocate(n);
		newEndData = newFirstData + n;
		std::uninitialized_copy(_firstData, _lastData, newFirstData);
		newLastData = newFirstData + this->size();
		this->clear();
		_alloc.deallocate(_firstData, this->capacity());
		_firstData = newFirstData;
		_lastData = newLastData;
		_endData = newEndData;
	}
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::operator[](size_type n)
{
	return (*(_firstData + n));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::operator[](size_type n) const
{
	return (*(_firstData + n));
}


template <class T, class Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::at(size_type n)
{
	if (this->size() < n)
		throw (std::out_of_range("out_of_range"));
	return (*(_firstData + n));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type n) const
{
	if (this->size() < n)
		throw (std::out_of_range("out_of_range"));
	return (*(_firstData + n));
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::front()
{
	return (*_firstData);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const
{
	return (*_firstData);
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::back()
{
	return (*(--_lastData));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const
{
	return (*(--_lastData));
}

// template <class T, class Allocator>
// template <class InputIterator>
// void
// vector<T, Allocator>::assign(InputIterator first, InputIterator last)
// {
//
// }

template <class T, class Allocator>
void
vector<T, Allocator>::assign(size_type n, const value_type& val)
{
	if (this->size() >= n)
	{
		this->clear();
		std::uninitialized_fill(_firstData, _firstData + n, val);
		_lastData = _firstData + n;
	}
	else
	{
		if (this->capacity() < n)
		{
			vector<T, Allocator> tmpVec(n, val);
			*this = tmpVec;
		}
		else
		{
			this->clear();
			std::uninitialized_fill(_firstData, _firstData + n, val);
			_lastData = _firstData + n;
		}
	}
}

template <class T, class Allocator>
void
vector<T, Allocator>::push_back(const value_type &val)
{
	this->resize(this->size() + 1, val);
}

template <class T, class Allocator>
void
vector<T, Allocator>::pop_back()
{
	_alloc.destroy(--_lastData);
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(iterator position, const value_type& val)
{
	size_type idxPos;

	idxPos = &(*position) - _firstData;
	this->insert(position, 1, val);
	return (iterator(_firstData + idxPos));
}

template <class T, class Allocator>
void
vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
{
	size_type idxPos;

	idxPos = &(*position) - _firstData;
	this->resize(this->size() + n);
	for (size_type lastIdx = this->size() - 1; lastIdx != idxPos; --lastIdx)
	{
		_alloc.destroy(_firstData + lastIdx);
		_alloc.construct(_firstData + lastIdx, *(_firstData + lastIdx - n));
	}
	for (size_type insertCnt = 0; insertCnt != n; ++insertCnt)
	{
		_alloc.destroy(_firstData + idxPos + insertCnt);
		_alloc.construct(_firstData + idxPos + insertCnt, val);
	}
}

// template <class T, class Allocator>
// template <class InputIterator>
// void
// vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last)
// {
//
// }

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(iterator position)
{
	size_type idxPos;
	size_type startIdx;
	size_type size;

	idxPos = &(*position) - _firstData;
	startIdx = idxPos + 1;
	size = this->size();
	while (startIdx < size)
	{
		_alloc.destroy(_firstData + startIdx - 1);
		_alloc.construct(_firstData + startIdx - 1, *(_firstData + startIdx));
		++startIdx;
	}
	_alloc.destroy(_firstData + startIdx - 1);
	--_lastData;
	return (iterator(_firstData + idxPos));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(iterator first, iterator last)
{
	size_type firstIdx;
	size_type lastIdx;
	size_type startIdx;
	size_type size;

	firstIdx = &(*first) - _firstData;
	lastIdx = &(*last) - _firstData;
	startIdx = firstIdx;
	size = this->size();
	for (size_type copyIdx = lastIdx; copyIdx < size; copyIdx++)
	{
		_alloc.destroy(_firstData + startIdx);
		_alloc.construct(_firstData + startIdx, *(_firstData + copyIdx));
		++startIdx;
	}
	_lastData = _firstData + startIdx;
	for (; startIdx < size; ++startIdx)
		_alloc.destroy(_firstData + startIdx);
	return (iterator(_firstData + firstIdx));
}


template <class T, class Allocator>
void
vector<T, Allocator>::swap(vector& x)
{
	if (x == *this)
		return;
	pointer tmpFirstData;
	pointer tmpLastData;
	pointer tmpEndData;
	allocator_type tmpAlloc;

	tmpFirstData = x._firstData;
	tmpLastData = x._lastData;
	tmpEndData = x._endData;
	tmpAlloc = x._alloc;
	x._firstData = _firstData;
	x._lastData = _lastData;
	x._endData = _endData;
	x._alloc = _alloc;
	_firstData = tmpFirstData;
	_lastData = tmpLastData;
	_endData = tmpEndData;
	_alloc = tmpAlloc;
}

template <class T, class Allocator>
void
vector<T, Allocator>::clear()
{
	for(size_type size = this->size(); size > 0; --size)
		_alloc.destroy(--_lastData);
}

template <class T, class Allocator>
typename vector<T, Allocator>::allocator_type
vector<T, Allocator>::get_allocator() const
{
	return (_alloc);
}

//---------------------------------------
//   vector<T, Allocator> non-member function overloads
//---------------------------------------

// relational operators
template <class T, class Allocator>
bool
operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// equal to (1)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename vector<T, Allocator>::const_iterator lBegin = lhs.begin();
	typename vector<T, Allocator>::const_iterator rBegin = rhs.begin();
	for (;lBegin != lhs.end(); ++lBegin, ++rBegin)
		if (*lBegin != *rBegin)
			return (false);
	return (true);
}

template <class T, class Allocator>
bool
operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// not equal to (2)
{
	return (!(lhs == rhs));
}

// template <class T, class Allocator>
// bool
// operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// less than (3)
// {
//
// }
//
// template <class T, class Allocator>
// bool
// operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// less than or equal to (4)
// {
//     return (!(rhs < lhs));
// }
//
// template <class T, class Allocator>
// bool
// operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// greater than (5)
// {
//     return (rhs < lhs);
// }
//
// template <class T, class Allocator>
// bool
// operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// greater than or equal to (6)
// {
//     return (!(lhs < rhs));
// }

template <class T, class Allocator>
void
swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
{
	x.swap(y);
}

}
#endif	/* vector_hpp */
