#ifndef reverseIterator_hpp
#define reverseIterator_hpp

#include "iterator.hpp"
namespace ft
{
//---------------------------------------
//   reverse_iterator<T> definition
//---------------------------------------
template <class Iterator>
class	reverse_iterator : iterator<typename iterator_traits<Iterator>::iterator_category,
									typename iterator_traits<Iterator>::value_type,
						   			typename iterator_traits<Iterator>::difference_type,
						  			typename iterator_traits<Iterator>::pointer,
						   			typename iterator_traits<Iterator>::reference>
{
	public:
	// member types
	typedef Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;

	// constructor
	reverse_iterator(void);										// default constructor
	explicit			reverse_iterator(iterator_type it);		// initialization constructor
	template<class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it);		// copy/type-cast constructor

	// member function
	iterator_type		base(void) const;

	// operator overloading
	reference			operator*(void) const;					// indirection
	pointer				operator->(void) const;					// member of pointer
	reverse_iterator&	operator++(void);						// prefix increment
	reverse_iterator	operator++(int);						// postfix increment
	reverse_iterator&	operator--(void);						// prefix decrement
	reverse_iterator	operator--(int);						// postfix decrement
	reverse_iterator	operator+(difference_type n) const;		// addition
	reverse_iterator	operator-(difference_type n) const;		// subtraction
	reverse_iterator&	operator+=(difference_type n);			// addition assignment
	reverse_iterator&	operator-=(difference_type n);			// subtraction assignment
	reference			operator[](difference_type n);			// subscript
	private:
	iterator_type	_ptr;
};

//---------------------------------------
//   reverse_iterator<T> definition
//---------------------------------------

// template <class Iterator>							<-- template function
// typename reverse_iterator<Iterator>::iterator_type	<-- return type
// reverse_iterator<Iterator>::base(void) const			<-- function name
// {													<-- function body
//     return (_ptr);
// }

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void) : _ptr()
{}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator it) : _ptr(it)
{}

template <class Iterator>
template <class Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it) : _ptr(rev_it.base())
{}

template <class Iterator>
typename reverse_iterator<Iterator>::iterator_type
reverse_iterator<Iterator>::base(void) const
{
	return (_ptr);
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator*(void) const
{
	iterator_type tmp(_ptr);
	--tmp;
	return (*tmp);
}

template <class Iterator>
typename reverse_iterator<Iterator>::pointer
reverse_iterator<Iterator>::operator->(void) const
{
	iterator_type tmp(_ptr);
	--tmp;
	return (&(*tmp));
}

template <class Iterator>
reverse_iterator<Iterator>&
reverse_iterator<Iterator>::operator++(void)
{
	--_ptr;
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator>
reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator<Iterator> tmp = *this;
	++(*this);
	return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator>&
reverse_iterator<Iterator>::operator--(void)
{
	++_ptr;
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator>
reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator<Iterator> tmp = *this;
	--(*this);
	return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator>
reverse_iterator<Iterator>::operator+(difference_type n) const
{
	reverse_iterator<Iterator> tmp(_ptr - n);
	return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator>
reverse_iterator<Iterator>::operator-(difference_type n) const
{
	reverse_iterator<Iterator> tmp(_ptr + n);
	return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator>&
reverse_iterator<Iterator>::operator+=(difference_type n)
{
	_ptr -= n;
	return (*this);
}

template <class Iterator>
reverse_iterator<Iterator>&
reverse_iterator<Iterator>::operator-=(difference_type n)
{
	_ptr += n;
	return (*this);
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator[](difference_type n)
{
	return (_ptr[-n -1]);
}

// non-member function overloads
// addition operator overriding
template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
{
	return (rev_it + n);
}

// subtraction operator overriding
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type
operator-(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	typename reverse_iterator<Iterator>::iterator_type lhsTmp;
	typename reverse_iterator<Iterator>::iterator_type rhsTmp;

	lhsTmp = lhs.base();
	rhsTmp = rhs.base();
	return (lhsTmp - rhsTmp);
}

template <class Iterator>
bool
operator==(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator_l, class Iterator_r>
bool
operator==(const reverse_iterator<Iterator_l>& lhs,
		const reverse_iterator<Iterator_r>& rhs)
{
	return (lhs.base() == rhs.base());
}
template <class Iterator>
bool
operator!=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator_l, class Iterator_r>
bool
operator!=(const reverse_iterator<Iterator_l>& lhs,
		const reverse_iterator<Iterator_r>& rhs)
{
	return (lhs.base() != rhs.base());
}
template <class Iterator>
bool
operator<(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator_l, class Iterator_r>
bool
operator<(const reverse_iterator<Iterator_l>& lhs,
		const reverse_iterator<Iterator_r>& rhs)
{
	return (lhs.base() > rhs.base());
}
template <class Iterator>
bool
operator>(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator_l, class Iterator_r>
bool
operator>(const reverse_iterator<Iterator_l>& lhs,
		const reverse_iterator<Iterator_r>& rhs)
{
	return (lhs.base() < rhs.base());
}
template <class Iterator>
bool
operator<=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator_l, class Iterator_r>
bool
operator<=(const reverse_iterator<Iterator_l>& lhs,
		const reverse_iterator<Iterator_r>& rhs)
{
	return (lhs.base() >= rhs.base());
}
template <class Iterator>
bool
operator>=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator_l, class Iterator_r>
bool
operator>=(const reverse_iterator<Iterator_l>& lhs,
		const reverse_iterator<Iterator_r>& rhs)
{
	return (lhs.base() <= rhs.base());
}
}
#endif
