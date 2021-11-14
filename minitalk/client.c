/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:59:54 by soum              #+#    #+#             */
/*   Updated: 2021/10/09 20:45:20 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"
#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int	send_sig(char let, int gv)
{
	unsigned char	bit;
	int				kill_error;

	kill_error = 0;
	bit = 1 << 6;
	while (bit)
	{
		if ((let & bit) == 0)
			kill_error = kill(gv, SIGUSR1);
		else
			kill_error = kill(gv, SIGUSR2);
		if (kill_error == -1)
		{
			ft_printf("kill error\n");
			return (kill_error);
		}
		bit >>= 1;
		usleep(100);
	}
	return (kill_error);
}

void	send_msg(char *pid, char *msg)
{
	int	int_pid;
	int	index;
	int	kill_error;

	kill_error = 0;
	index = 0;
	int_pid = ft_atoi(pid);
	while (msg[index] && (kill_error == 0))
	{
		kill_error = send_sig(msg[index], int_pid);
		index++;
	}
	if (kill_error == -1)
		return ;
	send_sig(msg[index], int_pid);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("./client [pid] [message] !!");
		return (0);
	}
	send_msg(argv[1], argv[2]);
	return (0);
}
