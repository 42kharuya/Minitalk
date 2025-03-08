/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <kharuya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:50:18 by kharuya           #+#    #+#             */
/*   Updated: 2024/05/14 10:28:14 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// static void check_strlen(size_t actual,size_t expected)
// {
// 	printf("%zu,%zu",actual,expected);
// 	if(actual == expected)
//         printf("\x1b[32m->[OK]\x1b[0m\n");
//     else
//         printf("\x1b[31m->[KO]\x1b[0m\n");
// }

// int main()
// {
// 	check_strlen(ft_strlen(""), strlen(""));
// 	check_strlen(ft_strlen("hello"), strlen("hello"));
// 	check_strlen(ft_strlen("hello world"), strlen("hello world"));
// }