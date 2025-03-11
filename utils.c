/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:14:35 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/11 04:49:02 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_handling(int error_check)
{
	if (error_check == INPUT_ERROR)
		ft_printf("Usage: ./client [PID] [string]\n");
	else if (error_check == PID_ERROR)
		ft_printf("PID is invalid\n");
	else if (error_check == KILL_ERROR)
		ft_printf("Kill command error\n");
	else if (error_check == USLEEP_ERROR)
		ft_printf("Usleep command error\n");
	else if (error_check == SIGEMPTYSET_ERROR)
		ft_printf("Sigemptyset command error\n");
	else if (error_check == SIGACTION_ERROR)
		ft_printf("Sigaction command error\n");
	else if (error_check == RESPONSE_ERROR)
		ft_printf("server is not responding\n");
	exit (EXIT_FAILURE);
}

int	try_kill(pid_t pid, int signum)
{
	int	i;

	i = 0;
	while (kill(pid, signum) == -1)
	{
		i++;
		if (i < 1000)
			return (-1);
	}
	return (0);
}
