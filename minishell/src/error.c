/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:45:42 by soum              #+#    #+#             */
/*   Updated: 2022/02/08 15:26:44 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	error_msg(char *str)
{
	printf("%s", str);
}

void	syntax_error_msg(char let)
{
	printf("minishell : syntax error near unexpected token '%c'\n", let);
}
