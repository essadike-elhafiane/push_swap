/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:09:26 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/01 00:09:26 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*ft_lstlastt(t_stk *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	sa(t_stk *a, char *s)
{
	int	tmp;
	int	tmp0;

	tmp = a->next->content;
	tmp0 = a->content;
	a->content = tmp;
	a->next->content = tmp0;
	if (s)
		ft_putstr_fd(s, 1);
}

void	rra(t_stk **a, char *s)
{
	t_stk	*tmp1;
	t_stk	*tmp;

	if (ft_lstsize((t_list *) *a) < 2)
		return ;
	if (a == NULL || *a == NULL)
		return ;
	tmp1 = *a;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp = ft_lstlastt(*a);
	tmp->next = NULL;
	tmp1->next = (*a);
	(*a) = tmp1;
	if (s)
		ft_putstr_fd(s, 1);
	tmp = NULL;
}

void	ra(t_stk **a, char *s)
{
	t_stk	*tmp;
	t_stk	*tmp1;

	if (a == NULL || *a == NULL)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = *a;
	(*a) = (*a)->next;
	tmp1->next = NULL;
	tmp->next = tmp1;
	if (s)
		ft_putstr_fd(s, 1);
}

void	pb(t_stk **a, t_stk **b, char *s)
{
	t_stk	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (s)
		ft_putstr_fd(s, 1);
}
