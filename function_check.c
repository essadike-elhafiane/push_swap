/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:36:14 by eelhafia          #+#    #+#             */
/*   Updated: 2023/01/22 16:54:36 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min(t_stk *a)
{
	int	c;

	c = a->content;
	while (a->next)
	{
		a = a->next;
		if (a->content < c)
			c = a->content;
	}
	return (c);
}

int	check_max(t_stk *a)
{
	int	c;

	c = a->content;
	while (a->next)
	{
		a = a->next;
		if (a->content > c)
			c = a->content;
	}
	return (c);
}

int	check_sort(t_stk *a)
{
	if ((a)->next == NULL)
		return (1);
	while ((a)->content < (a)->next->content && (a)->next != NULL)
	{
		if ((a)->next->next == NULL)
			return (1);
		(a) = (a)->next;
	}
	return (0);
}

int	check_place_min(t_stk *a)
{
	t_stk1	y;

	y.max = 0;
	y.i = ft_lstsize((t_list *)a);
	y.min = check_min(a);
	while (y.max <= y.i / 2)
	{
		if (a->content == y.min)
			return (1);
		a = a->next;
		y.max++;
	}
	return (0);
}

int	check_place_max(t_stk *b)
{
	t_stk1	y;

	y.min = 0;
	y.i = ft_lstsize((t_list *)b);
	y.max = check_max(b);
	while (y.min <= y.i / 2)
	{
		if (b->content == y.max)
			return (1);
		b = b->next;
		y.min++;
	}
	return (0);
}
