/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:31:15 by kharuya           #+#    #+#             */
/*   Updated: 2025/03/03 21:11:37 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// static void print_node(t_list *lst)
// {
// 	while(lst)
// 	{
// 		printf("%s -> ",(char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int main()
// {
//     t_list *list = NULL;

//     ft_lstadd_front(&list, ft_lstnew("three"));
//     ft_lstadd_front(&list, ft_lstnew("two"));
//     ft_lstadd_front(&list, ft_lstnew("one"));
// 	print_node(list);
// 	printf("%s\n",(char *)ft_lstlast(list) -> content);
// }