#ifndef iterator_hpp
#define iterator_hpp

#include <cstddef>
namespace ft
{
// ITERATOR CATEGORY
struct	input_iterator_tag {};
struct	output_iterator_tag {};
struct	forward_iterator_tag		: public input_iterator_tag			{};
struct	bidirectional_iterator_tag	: public forward_iterator_tag		{};
struct	random_access_iterator_tag	: public bidirectional_iterator_tag	{};

// TEMPLATE CLASSES
template <class Category, class T, class Distance = ptrdiff_t,
		 class Pointer = T*, class Reference = T&>
struct	iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef	Pointer		pointer;
	typedef Reference	reference;
	typedef Category 	iterator_category;
};

template<class Iterator>
struct	iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template<class T>
struct	iterator_traits<T*>
{
	typedef	ptrdiff_t						difference_type;
	typedef	T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef	random_access_iterator_tag		iterator_category;
};

template<class T>
struct	iterator_traits<const T*>
{
	typedef	ptrdiff_t						difference_type;
	typedef	T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef	random_access_iterator_tag		iterator_category;
};

template <typename T>
class	random_access_iterator : iterator<random_access_iterator_tag, T>
{
	public:
	typedef typename iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
	typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	typedef	T*																	pointer;
	typedef T&																	reference;

	// default constructor
	random_access_iterator() : _ptr(NULL)
	{}
	// constructor
	random_access_iterator(pointer ptr) : _ptr(ptr)
	{}
	// copy assignment operator
	random_access_iterator &operator=(const random_access_iterator &op)
	{
		if (this == &op)
			return (*this);
		this->_ptr = op._ptr;
		return (*this);
	}
	// destructor
	~random_access_iterator() {}

	reference operator* (void) const
	{
		return (*_ptr);
	}

	random_access_iterator &operator++( void )
	{
		_ptr++;
		return (*this);
	}

	random_access_iterator operator++( int )
	{
		random_access_iterator tmp(*this);
		_ptr++;
		return (tmp);
	}

	random_access_iterator &operator--( void )
	{
		_ptr--;
		return (*this);
	}

	random_access_iterator operator--( int )
	{
		random_access_iterator tmp(*this);
		_ptr--;
		return (tmp);
	}

	private:
		pointer _ptr;

};

template <typename T>
struct	reverse_iterator : iterator<bidirectional_iterator_tag, T>
{

};

}
#endif
