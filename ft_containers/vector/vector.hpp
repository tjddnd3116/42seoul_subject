#ifndef vector_hpp
#define vector_hpp

#include <iostream>
#include <memory>
#include <ostream>
#include "../iterator/randomAccessIterator.hpp"
#include "../iterator/reverseIterator.hpp"

namespace	ft
{

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
			const value_type& val,
			const allocator_type& alloc = allocator_type());
	template <class InputIterator>
				vector(InputIterator first,									// range constructor (3)
						InputIterator last,
						const allocator_type& alloc = allocator_type());
				vector(const vector& x);									// copy constructor (4)

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
	pointer			_firstData;
	pointer			_lastData;
	pointer			_endData;
	allocator_type	_alloc;
};

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
		const allocator_type& alloc) : _alloc(alloc)
{
	(void)first;
	(void)last;
	(void)alloc;
	// ???
}

template <class T, class Allocator>
vector<T, Allocator>::vector(const vector& x)
{
	(void)x;
	// ???
}

template <class T, class Allocator>
vector<T, Allocator>::~vector()
{
	// ???
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
			for (size_type size = this->size(); size > 0; --size)
				_alloc.destroy(--_lastData);
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
	if (this->capacity() < n)
	{
		pointer newFirstData;
		pointer newLastData;
		pointer newEndData;

		newFirstData = _alloc.allocate(n);
		newEndData = newFirstData + n;
		std::uninitialized_copy(_firstData, _lastData, newFirstData);
		newLastData = newFirstData + this->size();
		for (size_type size = this->size(); size > 0; --size)
			_alloc.destroy(--_lastData);
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
	// range exception
	return (*(_firstData + n));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type n) const
{
	// range exception
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

// non-member function overloads
//
// relational operators
// template <class T, class Allocator>
// bool
// operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// equal to (1)
// {
//
// }
//
// template <class T, class Allocator>
// bool
// operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// not equal to (2)
// {
//
// }
//
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
//
// }
//
// template <class T, class Allocator>
// bool
// operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// greater than (5)
// {
//
// }
//
// template <class T, class Allocator>
// bool
// operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	// greater than or equal to (6)
// {
//
// }
//
// template <class T, class Allocator>
// void
// swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
// {
//
// }

}
#endif	/* vector_hpp */
