/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:07:39 by soum              #+#    #+#             */
/*   Updated: 2022/04/26 21:53:50 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_hpp
#define MutantStack_hpp

#include <stack>
#include <iterator>
#include <vector>
#include <deque>
#include <list>


template< typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:

	public:
		MutantStack(){}
		MutantStack( const MutantStack<T, Container>& mutantstack ) {
			*this = mutantstack; }
		MutantStack<T, Container>& operator=( const MutantStack<T, Container>& mutantstack) {
			*this = mutantstack;
			return (*this); }
		~MutantStack(){}
		// begin end overriding
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin() {
			return (this->c.begin()); }

		iterator end() {
			return (this->c.end()); }
};

#endif
