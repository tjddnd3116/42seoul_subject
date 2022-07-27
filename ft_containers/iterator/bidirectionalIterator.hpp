#ifndef bidirectionalIterator_hpp
#define bidirectionalIterator_hpp

#include "iterator.hpp"
namespace ft {

//---------------------------------------
//   bidirectional_iterator<T> synopsis
//---------------------------------------
//
template <typename T>
class	bidirectional_iterator : ft::iterator<bidirectional_iterator_tag, T>
{
	public:
	// member types
	typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T*																	pointer;
	typedef T&																	reference;

	// constructor
	bidirectional_iterator(void);
	bidirectional_iterator(pointer ptr);
	bidirectional_iterator(const bidirectional_iterator& op);

	// destructor
	~bidirectional_iterator();

	// operator overloading
	bidirectional_iterator&		operator=(const bidirectional_iterator &op);		// copy assignment
	reference					operator*(void) const;								// indirection
	pointer						operator->(void) const;								// member of pointer
	bidirectional_iterator& 	operator++(void);									// prefix increment
	bidirectional_iterator		operator++(int);									// postfix increment
	bidirectional_iterator&		operator--(void);									// prefix decrement
	bidirectional_iterator		operator--(int);									// postfix decrement
	bool						operator==(const bidirectional_iterator &op) const;	// equal to
	bool						operator!=(const bidirectional_iterator &op) const;	// not equal to
	operator					bidirectional_iterator<const T>() const;			// conversion operator

	private :
	pointer _ptr;
};

//---------------------------------------
//   bidirectional_iterator<T> definition
//---------------------------------------

// template <typename T>						<-- template function
// bidirectional_iterator<T>&					<-- return type
// bidirectional_iterator<T>::operator++(void)	<-- function name
// {											<-- function body
//     _ptr++;
//     return (*this);
// }

template <typename T>
bidirectional_iterator<T>::bidirectional_iterator(void) : _ptr(NULL)
{}


template <typename T>
bidirectional_iterator<T>::bidirectional_iterator(pointer ptr) : _ptr(ptr)
{}

template <typename T>
bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator& op) : _ptr(op._ptr)
{}


template <typename T>
bidirectional_iterator<T>&
bidirectional_iterator<T>::operator=(const bidirectional_iterator<T> &op)
{
	if (this == &op)
		return (*this);
	this->_ptr = op._ptr;
	return (*this);
}

template <typename T>
typename bidirectional_iterator<T>::reference
bidirectional_iterator<T>::operator*(void) const
{
	return (*_ptr);
}

template <typename T>
typename bidirectional_iterator<T>::pointer
bidirectional_iterator<T>::operator->(void) const
{
	return (&(*_ptr));
}

template <typename T>
bidirectional_iterator<T>&
bidirectional_iterator<T>::operator++(void)
{
	_ptr++;
	return (*this);
}

template <typename T>
bidirectional_iterator<T>
bidirectional_iterator<T>::operator++(int)
{
	bidirectional_iterator tmp(*this);
	_ptr++;
	return (tmp);
}

template <typename T>
bidirectional_iterator<T>&
bidirectional_iterator<T>::operator--(void)
{
	_ptr--;
	return (*this);
}

template <typename T>
bidirectional_iterator<T>
bidirectional_iterator<T>::operator--(int)
{
	bidirectional_iterator tmp(*this);
	_ptr--;
	return (tmp);
}

template <typename T>
bool
bidirectional_iterator<T>::operator==(const bidirectional_iterator<T> &op) const
{
	return (_ptr == op._ptr);
}

template <typename T>
bool
bidirectional_iterator<T>::operator!=(const bidirectional_iterator<T> &op) const
{
	return (_ptr != op._ptr);
}

template <typename T>
bidirectional_iterator<T>::operator
bidirectional_iterator<const T>(void) const
{
	return (bidirectional_iterator<const T>(this->_ptr));
}

}
#endif
