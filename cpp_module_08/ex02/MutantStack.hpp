/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:07:39 by soum              #+#    #+#             */
/*   Updated: 2022/10/17 21:11:47 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_hpp
#define MutantStack_hpp

#include <stack>
#include <deque>
#include <list>

template< typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(){}
		MutantStack( const MutantStack<T, Container>& mutantstack ) {
			*this = mutantstack; }
		MutantStack<T, Container>& operator=( const MutantStack<T, Container>& mutantstack) {
			*this = mutantstack;
			return (*this); }
		~MutantStack(){}
		// begin end overriding
		//
		typedef typename std::deque<T>::iterator iterator;

		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator1;
		//
		typedef typename Container::reverse_iterator reverse_iterator;


		iterator begin() {
			return (this->c.begin()); }
		iterator end() {
			return (this->c.end()); }

		// typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		// typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() {
			return (this->c.rbegin()); }
		reverse_iterator rend() {
			return (this->c.rend()); }

		// typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const const_iterator cbegin() const {
			return (this->c.cbegin()); }
		const const_iterator cend() const {
			return (this->c.cend()); }

		// typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		const const_reverse_iterator crbegin() const {
			return (this->c.crbegin()); }
		const const_reverse_iterator crend() const {
			return (this->c.crend()); }
};

#endif
