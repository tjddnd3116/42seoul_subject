#ifndef vector_hpp
#define vector_hpp

#include <memory>
#include <iostream>
#include "../iterator/iterator.hpp"

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



	//	(1) default constructor
	explicit vector( const allocator_type& alloc= allocator_type() ) :_alloc(alloc)
	{
		create();
	}
	//	(2) fill constructor
	explicit	vector( size_type n , const value_type& val, const allocator_type& alloc= allocator_type()) :_alloc(alloc)
	{
		create(n, val);
	}
	//	(3) range constructor
	explicit	vector(iterator first, iterator last)
	{
		create(first, last);
	}
	//	(4) copy constructor - const
	vector( const vector& x) { create(x.begin(), x.end()); }
	//	(4) copy constructor - nomal
	vector( vector& x ) { create(x.begin(), x.end()); }

	// iterators
	iterator
	begin( )
	{
		return (_firstData);
	}

	iterator
	end( )
	{
		return (_lastData);
	}
	// capacity
	size_type
	size() const
	{
		return (_lastData - _firstData);
	}
	// myfunc
	void
	print_val()
	{
		pointer tmp;
		for (tmp = _firstData; tmp < _lastData; tmp++)
			std::cout << *tmp << std::endl;
	}

private:
			// member variable
			pointer		_firstData;
			pointer		_lastData;
			allocator_type	_alloc;
			// constructor memeber function overloading
			void	create() {
				_firstData = 0;
				_lastData = 0;
			}
			void	create( size_type n , const T& val) {
				_firstData = _alloc.allocate(n);
				_lastData = _firstData + n;
				std::uninitialized_fill(_firstData, _lastData, val);
			}
			void	create( iterator first, iterator last ){
				_firstData = _alloc.allocate(last - first);
				_lastData = std::uninitialized_copy(first, last, _firstData);
			}
	};
}
#endif	/* vector_hpp */
