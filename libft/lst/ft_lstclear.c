/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:13:52 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/03 21:11:37 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}

// static void cnt_free(void *p)
// {
// 	printf("%s\n",(char *)p);
//     free(p);
// }

// int main()
// {
// 	t_list  *elem1 = calloc(sizeof(t_list), 1);
//     t_list  *elem2 = calloc(sizeof(t_list), 1);
//     t_list  *elem3 = calloc(sizeof(t_list), 1);
// 	char    *s1 = strdup("hello");
//     char    *s2 = strdup("world");
//     char    *s3 = strdup("42!");
//     elem1->content = s1;
//     elem2->content = s2;
//     elem3->content = s3;
//     elem1->next = elem2;
//     elem2->next = elem3;
//     elem3->next = NULL;
// 	t_list  *lst = elem1;
// 	ft_lstclear(&lst, cnt_free);
// 	if(lst == NULL)
// 		printf("success to free!!\n");
// }