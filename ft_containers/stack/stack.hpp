#ifndef stack_hpp
#define	stack_hpp

#include "../vector/vector.hpp"

namespace ft
{

//---------------------------------------
//   stack<T, Container> synopsis
//---------------------------------------

template <class T, class Container = ft::vector<T> >
class stack
{
	public:
	// Member types
	typedef	T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;

	// constructor
	explicit			stack(const container_type& ctnr = container_type());

	// destructor
						~stack();
	// Member functions
	bool				empty() const;
	size_type			size() const;
	value_type&			top();
	const value_type&	top() const;
	void				push(const value_type& val);
	void				pop();

	private:
	container_type 		_cont;
};

//---------------------------------------
//   stack<T, Container> definition
//---------------------------------------

template <class T, class Container>
stack<T, Container>::stack(const container_type& ctnr) : _cont(ctnr)
{}

template <class T, class Container>
stack<T, Container>::~stack()
{}

template <class T, class Container>
bool
stack<T, Container>::empty() const
{
	return (this->_cont.empty());
}

template <class T, class Container>
typename stack<T, Container>::size_type
stack<T, Container>::size() const
{
	return (this->_cont.size());
}

template <class T, class Container>
typename stack<T, Container>::value_type&
stack<T, Container>::top()
{
	return (this->_cont.back());
}

template <class T, class Container>
const typename stack<T, Container>::value_type&
stack<T, Container>::top() const
{
	return (this->_cont.back());
}

template <class T, class Container>
void
stack<T, Container>::push(const value_type& val)
{
	this->_cont.push_back(val);
}

template <class T, class Container>
void
stack<T, Container>::pop()
{
	this->_cont.pop_back();
}

//---------------------------------------
//   stack<T, Container> non-member function overloads
//---------------------------------------

// relational operators
template <class T, class Container>
bool
operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	// equal to (1)
{
	return (lhs._cont == rhs._cont);
}

template <class T, class Container>
bool
operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	// not equal to (2)
{
	return (lhs._cont != rhs._cont);
}

template <class T, class Container>
bool
operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	// less than (3)
{
	return (lhs._cont < rhs._cont);
}

template <class T, class Container>
bool
operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	// less than or equal to (4)
{
	return (lhs._cont <= rhs._cont);
}

template <class T, class Container>
bool
operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	// greater than (5)
{
	return (lhs._cont > rhs._cont);
}

template <class T, class Container>
bool
operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	// greater than or equal to (6)
{
	return (lhs._cont >= rhs._cont);
}

}
#endif
