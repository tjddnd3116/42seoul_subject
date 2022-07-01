#ifndef vector_hpp
#define vector_hpp

#include <memory>
#include <iostream>
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
	explicit	vector(const allocator_type& alloc = allocator_type());		// default constructor
	explicit	vector(size_type				n,							// fill constructor
					   const value_type&		val,
					   const allocator_type&	alloc = allocator_type());
	template <class InputIterator>
				vector(InputIterator			first,						// range constructor
					   InputIterator			last,
					   const allocator_type&	alloc = allocator_type());
				vector(const vector& x);									// copy constructor

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
	void					assign(InputIterator first,						// range
								   InputIterator last);
	void					assign(size_type n,								// fill
								   const value_type& val = value_type());
	void					push_back(const value_type& val);
	void					pop_back();
	iterator				insert(iterator position,						// single element
								   const value_type& val = value_type());
	void					insert(iterator position, size_type n,			// fill
								   const value_type& val = value_type());
	template <class InputIterator>
	void					insert(iterator position,						// range
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
	allocator_type	_alloc;

	// void	create() {
	//     _firstData = 0;
	//     _lastData = 0;
	// }
	// void	create( size_type n , const T& val)
	// {
	//     _firstData = _alloc.allocate(n);
	//     _lastData = _firstData + n;
	//     std::uninitialized_fill(_firstData, _lastData, val);
	// }
	// void	create( pointer first, pointer last ){
	//     _firstData = _alloc.allocate(last - first);
	//     _lastData = std::uninitialized_copy(first, last, _firstData);
	// }
};

template <class T, class Allocator>
vector<T, Allocator>::vector(const allocator_type& alloc) : _alloc(alloc)
{

}

template <class T, class Allocator>
vector<T, Allocator>::vector(size_type n,
							 const value_type& val,
							 const allocator_type& alloc) : _alloc(alloc)
{}

template <class T, class Allocator>
template<class InputIterator>
vector<T, Allocator>::vector(InputIterator first, InputIterator last,
							 const allocator_type& alloc)
{

}

template <class T, class Allocator>
vector<T, Allocator>::vector(const vector& x)
{

}

template <class T, class Allocator>
vector<T, Allocator>::~vector()
{}

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

}
#endif	/* vector_hpp */
