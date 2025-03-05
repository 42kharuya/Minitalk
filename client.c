/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:33:11 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/05 22:33:07 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

// static void	change_to_binary(pid_t server_pid, char *str)
// {
// 	// int	char_ascii;

// 	// char_ascii = *str;
// 	(void)str;
// 	if (kill (server_pid, SIGUSR1) == -1)
// 			return ;
// }

// int main(int argc, char *argv[])
// {
// 	if (argc != 3 || (pid_t)ft_atoi(argv[1]) <= 0)
// 		return (1);
// 	change_to_binary((pid_t)ft_atoi(argv[1]), argv[2]);
// 	return 0;
// }

// グローバル変数あり

// 使用するコマンド
// exit
// kill
// usleep

// エラーケース
// input_error
// pid_error
// kill_error


int main(void)
{
	static int i;

	ft_printf ("static int:%d\n", i);
	return (0);
}
