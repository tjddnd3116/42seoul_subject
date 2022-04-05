/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:32:05 by soum              #+#    #+#             */
/*   Updated: 2022/04/05 19:40:21 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl {
	private:
		void debug( void );
		void info( void);
		void warning( void );
		void error( void );
	public:
		void complain( std::string level );
};

#endif
