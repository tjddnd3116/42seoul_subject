#ifndef randomAccessIterator_hpp
#define randomAccessIterator_hpp

#include "iterator.hpp"
namespace ft {

//---------------------------------------
//   random_access_iterator<T> synopsis
//---------------------------------------

template <typename T>
class	random_access_iterator : iterator<random_access_iterator_tag, T>
{
	public:
	// member types
	typedef typename iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	typedef	T*																	pointer;
	typedef T&																	reference;

	// constructor
	random_access_iterator(void);													// default constructor
	random_access_iterator(pointer ptr);											// copy constructor
	random_access_iterator(const random_access_iterator& op);

	// destructor
	~random_access_iterator();

	// operator overloading
	random_access_iterator&		operator=(const random_access_iterator &op);		// copy assignment
	reference					operator*(void) const;								// indirection
	pointer						operator->(void) const;								// member of pointer
	random_access_iterator& 	operator++(void);									// prefix increment
	random_access_iterator		operator++(int);									// postfix increment
	random_access_iterator&		operator--(void);									// prefix decrement
	random_access_iterator		operator--(int);									// postfix decrement
	random_access_iterator		operator+(difference_type n) const;					// addition
	random_access_iterator		operator-(difference_type n) const;					// subtraction
	random_access_iterator		operator+=(difference_type n);						// addition assignment
	random_access_iterator		operator-=(difference_type n);						// subtraction assignment
	reference					operator[](difference_type n);						// subscript
	bool						operator==(const random_access_iterator &op) const;	// equal to
	bool						operator!=(const random_access_iterator &op) const;	// not equal to
	bool						operator<(const random_access_iterator &op) const;	// less than
	bool						operator>(const random_access_iterator &op) const;	// greater than
	bool						operator<=(const random_access_iterator &op) const;	// less than or equal to
	bool						operator>=(const random_access_iterator &op) const;	// greater than or equal to
	operator					random_access_iterator<const T>() const;			// conversion operator

	private:
	pointer _ptr;
};

//---------------------------------------
//   random_access_iterator<T> definition
//---------------------------------------

// template <typename T>						<-- template function
// random_access_iterator<T>&					<-- return type
// random_access_iterator<T>::operator++(void)	<-- function name
// {											<-- function body
//     _ptr++;
//     return (*this);
// }

template <typename T>
random_access_iterator<T>::random_access_iterator(void) : _ptr(NULL)
{}

template <typename T>
random_access_iterator<T>::random_access_iterator(pointer ptr) : _ptr(ptr)
{}

template <typename T>
random_access_iterator<T>::random_access_iterator(const random_access_iterator& op) : _ptr(op._ptr)
{}

template <typename T>
random_access_iterator<T>::~random_access_iterator()
{}

template <typename T>
random_access_iterator<T>&
random_access_iterator<T>::operator=(const random_access_iterator<T> &op)
{
	if (this == &op)
		return (*this);
	this->_ptr = op._ptr;
	return (*this);
}

template <typename T>
typename random_access_iterator<T>::reference
random_access_iterator<T>::operator*(void) const
{
	return (*_ptr);
}

template <typename T>
typename random_access_iterator<T>::pointer
random_access_iterator<T>::operator->(void) const
{
	return (&(*_ptr));
}

template <typename T>
random_access_iterator<T>&
random_access_iterator<T>::operator++(void)
{
	_ptr++;
	return (*this);
}

template <typename T>
random_access_iterator<T>
random_access_iterator<T>::operator++(int)
{
	random_access_iterator tmp(*this);
	_ptr++;
	return (tmp);
}

template <typename T>
random_access_iterator<T>&
random_access_iterator<T>::operator--(void)
{
	_ptr--;
	return (*this);
}

template <typename T>
random_access_iterator<T>
random_access_iterator<T>::operator--(int)
{
	random_access_iterator tmp(*this);
	_ptr--;
	return (tmp);
}

template <typename T>
random_access_iterator<T>
random_access_iterator<T>::operator-(difference_type n) const
{
	return (_ptr - n);
}

template <typename T>
random_access_iterator<T>
random_access_iterator<T>::operator+(difference_type n) const
{
	return (_ptr + n);
}

template <typename T>
random_access_iterator<T>
random_access_iterator<T>::operator+=(difference_type n)
{
	_ptr += n;
	return (*this);
}

template <typename T>
random_access_iterator<T>
random_access_iterator<T>::operator-=(difference_type n)
{
	_ptr -= n;
	return (*this);
}

template <typename T>
typename random_access_iterator<T>::reference
random_access_iterator<T>::operator[](difference_type n)
{
	return (*(_ptr + n));
}

template <typename T>
bool
random_access_iterator<T>::operator==(const random_access_iterator<T> &op) const
{
	return (_ptr == op._ptr);
}

template <typename T>
bool
random_access_iterator<T>::operator!=(const random_access_iterator<T> &op) const
{
	return (_ptr != op._ptr);
}

template <typename T>
bool
random_access_iterator<T>::operator<(const random_access_iterator<T> &op) const
{
	return (_ptr < op._ptr);
}

template <typename T>
bool
random_access_iterator<T>::operator>(const random_access_iterator<T> &op) const
{
	return (_ptr > op._ptr);
}

template <typename T>
bool
random_access_iterator<T>::operator<=(const random_access_iterator<T> &op) const
{
	return (_ptr <= op._ptr);
}

template <typename T>
bool
random_access_iterator<T>::operator>=(const random_access_iterator<T> &op) const
{
	return (_ptr >= op._ptr);
}

template <typename T>
random_access_iterator<T>::operator
random_access_iterator<const T>(void) const
{
	return (random_access_iterator<const T>(this->_ptr));
}

// non-member function overloads
// addition operator overriding
template <typename T>
random_access_iterator<T>
operator+(typename random_access_iterator<T>::difference_type n,
		random_access_iterator<T>& op)
{
	return (op + n);
}

// subtraction operator overriding
template <typename T>
typename random_access_iterator<T>::difference_type
operator-(random_access_iterator<T>& lhs,
		random_access_iterator<T>& rhs)
{
	return (&(*lhs) - &(*rhs));
}

}
#endif
