/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:03:24 by soum              #+#    #+#             */
/*   Updated: 2022/04/18 16:03:24 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_hpp
#define Brain_hpp

#include <iostream>

class Brain
{
		private:
			std::string _ideas[100];

		public:
			Brain();
			Brain( std::string idea );
			Brain( const Brain& );
			Brain& operator=( const Brain& brain );
			~Brain();

};
#endif
