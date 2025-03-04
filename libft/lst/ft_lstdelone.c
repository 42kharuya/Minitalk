/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:56:39 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/03 21:11:37 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void	*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// static void cnt_free(void *p)
// {
// 	printf("%s\n",(char *)p);
//     free(p);
// }

// int main()
// {
// 	t_list  *node = (t_list *)calloc(sizeof(t_list), 1);
// 	char    *s1 = strdup("hello");
// 	node->content = s1;
// 	ft_lstdelone(node, cnt_free);
// 	//this part will be segf cuz the node was freed.
// 	printf("%d\n",ft_lstsize(node));
// }