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
	ft_putstr_fd (s, 1);
}

void    rra(t_stk **a, char *s)
{
    t_stk    *tmp1;
    t_stk    *tmp;

    tmp1 = *a;
    while (tmp1->next)
        tmp1 = tmp1->next;
    tmp1 = ft_new(tmp1->content);
    tmp = ft_lstlasttt(*a);
    tmp1->next = (*a);
    (*a) = tmp1;
    tmp1 = ft_lstlastt(*a);
    tmp1->next = NULL;
	ft_putstr_fd (s, 1);
    free(tmp);
	tmp = NULL;
}

void	ra(t_stk **a, char *s)
{
	if(a == NULL || *a == NULL)
		return;
	t_stk	*tmp;
	t_stk	*tmp1;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new((*a)->content);
	tmp1 = *a;
	(*a) = (*a)->next;
	tmp = (*a);
	ft_putstr_fd(s, 1);
	function_free(tmp1);
}

void	pb(t_stk **a, t_stk **b, char *s)
{
	t_stk	*tmp;
	t_stk	*tmp1;

	if (!(*a))
		return ;
	tmp1 = (*a);
	tmp = ft_new((*a)->content);
	tmp->next = *b;
	*b = tmp;
	*a = (*a)->next;
	ft_putstr_fd(s, 1);
	free(tmp1);
	tmp1 = NULL;
}
