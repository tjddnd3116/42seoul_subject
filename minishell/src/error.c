/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:45:42 by soum              #+#    #+#             */
/*   Updated: 2022/02/12 18:04:58 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../Libft/libft.h"

void	error_msg(char *str)
{
	printf("%s", str);
}

int	syntax_error_msg(char let)
{
	printf("minishell : syntax error near unexpected token '%c'\n", let);
	return (1);
}
