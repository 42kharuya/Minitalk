/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:33:11 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/09 18:54:02 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_handling(int error_check)
{
	if (error_check == INPUT_ERROR)
		ft_printf("Usage: ./client [PID] [string]\n");
	else if (error_check == PID_ERROR)
		ft_printf("PID is invalid\n");
	else if (error_check == KILL_ERROR)
		ft_printf("Kill command error\n");
	else if (error_check == USLEEP_ERROR)
		ft_printf("Usleep command error\n");
	exit (EXIT_FAILURE);
}

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
		if (usleep(500) == -1)
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
