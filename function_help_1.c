/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:00:36 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/28 01:04:50 by eelhafia         ###   ########.fr       */
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

void	double_mov(t_stk **a, t_stk **b, int i, int max)
{
	t_stk1		y;

	y.min = ft_lstsize((t_list *) *b);
	if (y.min > 2)
	{
		if ((*a)->content > max && (*b)->content > i)
			rr(a, b, "rr\n");
		else if ((*b)->content > i)
			ra(b, "rb\n");
	}
}

void	len_div(t_stk1 *y, t_stk **a, int div, int div_next)
{
	int		*s;
	int		len;

	s = check_pivot(*a);
	len = ft_lstsize((t_list *) *a);
	y->max = s[len / div];
	y->min = s[len / div / div_next];
	free(s);
}
