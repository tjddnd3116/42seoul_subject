#ifndef funtional_hpp
#define funtional_hpp

namespace ft {

//---------------------------------------
//   binary_funtion<Arg1, Arg2, result> synopsis
//---------------------------------------

template <class Arg1, class Arg2, class result>
struct binary_funtion
{
	// member types
	typedef Arg1	first_argument_type;
	typedef Arg2	secont_argument_type;
	typedef result	result_type;
};

//---------------------------------------
//   less<T> synopsis
//---------------------------------------

template <class T>
struct less : binary_funtion<T, T, bool>
{
	// member funtions
	bool operator() (const T& x, const T& y) const;
};

//---------------------------------------
//   less<T> definition
//---------------------------------------

template <class T>
bool
less<T>::operator()(const T &x, const T &y) const
{
	return (x < y);
}

}
#endif
