/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:39:10 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/07 19:54:00 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_acknowledge_check = 0;

static void	ack_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		g_acknowledge_check = 1;
	else if (signum == SIGUSR2)
		write(STDOUT_FILENO, "✅Message Received✅", 22);
}

void	error_message(void)
{
	ft_printf("🙅🚫[ERROR]🚫🙅\n");
	ft_printf("Correct Usage: ./client <PID> \"message\"\n");
	exit(EXIT_FAILURE);
}

void	send_char(__pid_t pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_acknowledge_check = 0;
		if (c & (0b10000000 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (!g_acknowledge_check)
		{
			pause();
		}
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	__pid_t				server_pid;
	int					i;
	struct sigaction	ack_action;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3 || server_pid <= 0)
		error_message();
	message = argv[2];
	ack_action.sa_flags = SA_SIGINFO;
	ack_action.sa_sigaction = ack_handler;
	sigemptyset(&ack_action.sa_mask);
	sigaddset(&ack_action.sa_mask, SIGUSR1);
	sigaddset(&ack_action.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &ack_action, NULL) < 0)
		exit (1);
	if (sigaction(SIGUSR2, &ack_action, NULL) < 0)
		exit (1);
	i = 0;
	while (message[i])
		send_char(server_pid, message[i++]);
	send_char(server_pid, '\0');
	return (0);
}
