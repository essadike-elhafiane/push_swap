/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:33:21 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/25 01:55:54 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_max_help(t_stk **b, t_stk **a, int max)
{
	while (!check_place_max(*b) && ft_lstsize((t_list *)*b) > 1)
	{
		if (max == (*b)->content)
		{
			pb(b, a, "pa\n");
			max = check_max(*b);
			check_place_max(*b);
		}
		else
			rra(b, "rrb\n");
	}
}

void	swap_min_help(t_stk **a, t_stk **b, int min)
{
	while (!check_place_min(*a) && ft_lstsize((t_list *)*a) > 3)
	{
		if (check_sort(*a))
			return ;
		if (min == (*a)->content)
		{
			pb(a, b, "pb\n");
			min = check_min(*a);
			check_place_min(*a);
		}
		else
			rra(a, "rra\n");
	}
}

int	chek_sort_arr(int *s, int j)
{
	int	i;

	i = 0;
	while (s[i] <= s[i +1] && i < j -1)
	{
		if (i == j -2)
			return (1);
		i++;
	}
	return (0);
}

int	*push_arr(t_stk *a, int len)
{
	int	i;
	int	*s;

	s = malloc(len * sizeof(int));
	if (!s)
		return (0);
	i = 0;
	while (a)
	{
		s[i++] = a->content;
		a = a->next;
	}
	return (s);
}

int	*check_pivot(t_stk *a)
{
	t_stk1		y;
	int			*s;

	y.max = ft_lstsize((t_list *)a);
	s = push_arr(a, y.max);
	y.i = -1;
	while (!chek_sort_arr(s, y.max))
	{
		while (y.i++ < y.max - 2)
		{
			if (s[y.i] > s[y.i +1])
			{
				y.min = s[y.i];
				s[y.i] = s[y.i +1];
				s[y.i +1] = y.min;
			}
		}
		y.i = -1;
	}
	return (s);
}
