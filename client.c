/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:33:11 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/11 09:06:57 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_c(char c, pid_t pid)
{
	int	shift_count;
	int	sig;

	shift_count = 7;
	while (shift_count >= 0)
	{
		if ((c >> shift_count) & 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(pid, sig) == -1)
			error_handling(KILL_ERROR);
		if (usleep(50) == -1)
			error_handling(USLEEP_ERROR);
		shift_count--;
	}
	return ;
}

static void	pid_check(pid_t pid)
{
	if (pid <= 1)
		error_handling(PID_ERROR);
	return ;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
		error_handling(INPUT_ERROR);
	pid = (pid_t)ft_atoi(argv[1]);
	pid_check (pid);
	message = argv[2];
	while (*message)
	{
		send_c(*message, pid);
		message++;
	}
	exit(EXIT_SUCCESS);
}
