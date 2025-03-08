/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:33:17 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/08 21:15:49 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_handling(int error_check)
{
	if (error_check == SIGEMPTYSET_ERROR)
		ft_printf("Sigemptyset command error\n");
	else if (error_check == SIGACTION_ERROR)
		ft_printf("Sigaction command error\n");
	exit (EXIT_FAILURE);
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				shift_count = 7;
	static unsigned char	c;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << shift_count);
	shift_count--;
	if (shift_count < 0)
	{
		write (1, &c, 1);
		shift_count = 7;
		c = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("[PID]%d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1)
		error_handling(SIGEMPTYSET_ERROR);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handling(SIGACTION_ERROR);
	while (1)
		pause();
	return (0);
}

// sigaction
// sigemptyset
// kill
// get_pid
// pause