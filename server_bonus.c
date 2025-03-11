/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:24:01 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/11 09:47:47 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_client_pid;

static void	init_bit_count(unsigned char *utf_char, int *bit_count)
{
	*bit_count = 0;
	utf_char[0] = 0;
	utf_char[1] = 0;
	utf_char[2] = 0;
	utf_char[3] = 0;
	utf_char[4] = 0;
	return ;
}

static int	count_bit_size(unsigned char first_byte)
{
	if ((first_byte & 0xF0) == 0xF0)
		return (32);
	if ((first_byte & 0xE0) == 0xE0)
		return (24);
	if ((first_byte & 0xC2) == 0xC2)
		return (16);
	else
		return (8);
}

static void	sig_operation(unsigned char *utf_char, int *bit_count, int signum)
{
	int	utf_index;

	utf_index = (*bit_count) / 8;
	utf_char[utf_index] <<= 1;
	if (signum == SIGUSR1)
		utf_char[utf_index] += 1;
	(*bit_count)++;
	return ;
}

static void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	utf_char[5];
	static int				bit_count;
	int						bit_size;
	int						i;

	(void)context;
	if (g_client_pid != siginfo->si_pid && siginfo->si_pid != 0)
		init_bit_count(utf_char, &bit_count);
	sig_operation(utf_char, &bit_count, signum);
	bit_size = count_bit_size(utf_char[0]);
	if (bit_count == bit_size)
	{
		i = 0;
		while (utf_char[i] != '\0')
			write (1, &utf_char[i++], 1);
		init_bit_count(utf_char, &bit_count);
	}
	if (siginfo->si_pid != 0)
		g_client_pid = siginfo->si_pid;
	if (try_kill(g_client_pid, SIGUSR1) == -1)
		init_bit_count(utf_char, &bit_count);
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("[PID]%d\n", getpid());
	sa.sa_sigaction = signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		error_handling(SIGEMPTYSET_ERROR);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handling(SIGACTION_ERROR);
	while (1)
		pause();
	return (0);
}

//siginfo->s1_pidが0の時
//write errorの処理
//0スタートのため、bit_countの最大値は32bit
// ↓意味わからん
// if (try_kill(g_client_pid, SIGUSR1) == -1)
// 		init_bit_count(utf_char, &bit_count);
