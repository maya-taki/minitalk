/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:39:20 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/06 20:58:04 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	bit;
	static unsigned char	c;

	(void)context;
	if (signum == SIGUSR1)
		c |= 0b10000000 >> bit;
	if (signum == SIGUSR2)
		c &= ~(0b10000000 >> bit);
	++bit;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("✅💯 Initializing server 💯✅\n");
	ft_printf("Process ID: %d\n", getpid());
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
