/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:47:00 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/07 20:20:11 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*lstmap;

	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		lstmap = ft_lstnew(f(lst->content));
		ft_lstclear(&newlst, del);
		ft_lstadd_back(&newlst, lstmap);
		lst = lst->next;
	}
	return (newlst);
}

// void * f(void * ss)
// {
// 	return ss;
// }
// void del(void * mm)
// {
// 	return ;
// }
// int main()
// {
// t_list *p1,*p2;
//     p1 = malloc(sizeof(t_list));
//     p2 = malloc(sizeof(t_list));  
//     p1->content = "11";
//     p1->next = p2;
//      p2->content = "22";
//     p2->next = NULL;
//     ft_lstmap(p1,f,del);
// }