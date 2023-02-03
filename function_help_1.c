/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:00:36 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/01 14:13:00 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	fun_free(t_stk **a)
{
	t_stk	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	a = NULL;
}

t_stk	*g_lst(t_stk *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stk	*function_free(t_stk *tmp)
{
	t_stk1			y;
	static t_stk	*g_tmp;
	t_stk			*a;

	y.i = 0;
	tmp->next = NULL;
	if (!g_tmp)
		g_tmp = tmp;
	else
	{
		a = g_lst(g_tmp);
		a->next = tmp;
	}
	return (g_tmp);
}

t_stk	*ft_lstlasttt(t_stk *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
