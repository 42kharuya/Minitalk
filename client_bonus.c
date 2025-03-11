/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:24:08 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/11 08:50:17 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_server_pid;

static void	wait_respond(void)
{
	int	time;

	time = 0;
	while (g_server_pid < 0)
	{
		usleep(100);
		time++;
		if (time > 1000)
			error_handling(RESPONSE_ERROR);
	}
	return ;
}

static void	send_8_bit(char c, pid_t pid)
{
	int		shift_count;
	int		sig;

	shift_count = 7;
	while (shift_count >= 0)
	{
		wait_respond();
		g_server_pid *= -1;
		if ((c >> shift_count) & 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (try_kill(pid, sig) == -1)
			error_handling(KILL_ERROR);
		shift_count--;
	}
	return ;
}

static void	send_message(char *message, pid_t pid)
{
	g_server_pid = pid;
	while (1)
	{
		send_8_bit(*message, pid);
		if (*message == '\0')
			break ;
		message++;
	}
	return ;
}

static void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)signum;
	(void)context;
	if (siginfo->si_pid == (g_server_pid * -1) || siginfo->si_pid == 0)
		g_server_pid *= -1;
	return ;
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
		error_handling(INPUT_ERROR);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 1)
		error_handling(PID_ERROR);
	sa.sa_sigaction = signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		error_handling(SIGEMPTYSET_ERROR);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_handling(SIGACTION_ERROR);
	send_message(argv[2], pid);
	exit(EXIT_SUCCESS);
}

//usleep中に割り込み処理が来たときはusleep_errorになる