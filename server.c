/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:33:17 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/11 09:11:46 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum)
{
	static int				shift_count = 7;
	static unsigned char	c;

	c <<= 1;
	if (signum == SIGUSR1)
		c += 1;
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
	sa.sa_handler = signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		error_handling(SIGEMPTYSET_ERROR);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handling(SIGACTION_ERROR);
	while (1)
		pause();
	return (0);
}
