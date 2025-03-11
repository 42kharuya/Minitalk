/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:33:19 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/11 04:49:25 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// include
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <signal.h>

# define INPUT_ERROR 1
# define PID_ERROR 2
# define KILL_ERROR 3
# define USLEEP_ERROR 4
# define SIGEMPTYSET_ERROR 5
# define SIGACTION_ERROR 6
# define RESPONSE_ERROR 7

//prototype
void	error_handling(int error_check);
int		try_kill(pid_t pid, int signum);

#endif