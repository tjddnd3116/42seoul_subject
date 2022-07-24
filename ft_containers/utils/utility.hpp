#ifndef utility_hpp
#define utility_hpp

namespace ft
{

//---------------------------------------
//   pair<T1, T2> synopsis
//---------------------------------------

template <class T1, class T2>
struct pair
{
	// member types
	typedef T1	first_type;
	typedef T2	second_type;

	// member variable
	first_type	first;
	second_type	second;

	//	constructor
	pair();												// default constructor (1)
	template<class U, class V>
	pair(const pair<U, V>& pr);							// copy constructor (2)
	pair(const first_type& a, const second_type& b);	// initialization constructor (3)

	// operator
	pair	&operator=(const pair& pr);					// copy assignment operator
};

//---------------------------------------
//   pair<T1, T2> definition
//---------------------------------------

template <class T1, class T2>
pair<T1, T2>::pair() : first(), second()
{}

template <class T1, class T2>
template <class U, class V>
pair<T1, T2>::pair(const pair<U, V>& pr) : first(pr.first), second(pr.second)
{}

template <class T1, class T2>
pair<T1, T2>::pair(const first_type& a, const second_type& b) : first(a), second(b)
{}

template <class T1, class T2>
pair<T1, T2>&
pair<T1, T2>::operator=(const pair &pr)
{
	if (*this == pr)
		return (*this);
	first = pr.first;
	second = pr.second;
	return (*this);
}

// relational operators (pair)
template <class T1, class T2>
bool
operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool
operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool
operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool
operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool
operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool
operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(lhs < rhs));
}

}
#endif
