/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:01:51 by soum              #+#    #+#             */
/*   Updated: 2022/12/12 15:43:14 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	int j;
	std::string arr;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (islower(argv[i][j]))
					argv[i][j] = toupper(argv[i][j]);
				j++;
			}
			arr = argv[i];
			std::cout << arr;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
