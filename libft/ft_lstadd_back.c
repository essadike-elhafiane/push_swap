/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:29:43 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/10 21:47:01 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*llst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		llst = ft_lstlast(*lst);
		llst->next = new;
	}
	return ;
}
