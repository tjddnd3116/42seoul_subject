/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:00:04 by soum              #+#    #+#             */
/*   Updated: 2021/10/09 20:44:26 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"
#include "./includes/ft_printf.h"
#include "./includes/libft.h"

void	init_info(void)
{
	g_print_msg.message = '\0';
	g_print_msg.bit = 1 << 6;
	g_print_msg.cnt = 0;
}

void	turn_on_bit(void)
{
	if (g_print_msg.cnt == 7)
		init_info();
	g_print_msg.message += g_print_msg.bit;
	g_print_msg.bit >>= 1;
	g_print_msg.cnt++;
}

void	turn_off_bit(void)
{
	if (g_print_msg.cnt == 7)
		init_info();
	g_print_msg.bit >>= 1;
	g_print_msg.cnt++;
}

void	handle_s(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		turn_off_bit();
	else if (sig == SIGUSR2)
		turn_on_bit();
}

int	main(void)
{
	struct sigaction	sigact;
	int					i;

	i = 0;
	sigact.sa_sigaction = handle_s;
	sigact.sa_flags = SA_SIGINFO;
	ft_printf("pid : %d\n", getpid());
	init_info();
	if (sigaction(SIGUSR1, &sigact, NULL) != 0)
		return (!ft_printf("error\n"));
	if (sigaction(SIGUSR2, &sigact, NULL) != 0)
		return (!ft_printf("error\n"));
	while (1)
	{
		pause();
		if (g_print_msg.cnt == 7)
		{
			if (!g_print_msg.message)
				write(1, "\n", 1);
			else
				ft_printf("%c", g_print_msg.message);
		}
	}
}
