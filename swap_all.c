/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:59:16 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/27 22:02:42 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_5(t_stk **a, t_stk **b)
{
	t_stk1	y;

	y.i = 0;
	y.max = 0;
	y.min = check_min(*a);
	while (y.i <= 4 && y.max < 2)
	{
		if (y.min == (*a)->content)
		{
			y.max++;
			y.i = 0;
			pb(a, b, "pb\n");
			y.min = check_min(*a);
		}
		else if ((int )ft_lstlast((t_list *)*a)->content == y.min)
			rra(a, "rra\n");
		else
			ra(a, "ra\n");
		y.i++;
	}
	if (!check_sort(*a))
		swap_3(a);
	pb(b, a, "pa\n");
	pb(b, a, "pa\n");
}

void	swap_min(t_stk **a, t_stk **b)
{
	t_stk1	y;

	y.min = check_min(*a);
	while (ft_lstsize((t_list *)*a) > 3)
	{
		if (check_place_min(*a))
		{
			while (check_place_min(*a) && ft_lstsize((t_list *)*a) > 3)
			{
				if (y.min == (*a)->content)
				{
					pb(a, b, "pb\n");
					y.min = check_min(*a);
					check_place_min(*a);
				}
				else
					ra(a, "ra\n");
			}
		}
		if (!check_place_min(*a))
			swap_min_help(a, b, y.min);
	}
	swap_3(a);
}

void	swap_max(t_stk **b, t_stk **a)
{
	t_stk1	y;

	y.max = check_max(*b);
	y.j = 0;
	while (ft_lstsize((t_list *)*b) > 1)
	{
		if (check_place_max(*b))
		{
			while (check_place_max(*b) && ft_lstsize((t_list *)*b) > 1)
			{
				if (y.max == (*b)->content)
				{
					pb(b, a, "pa\n");
					y.max = check_max(*b);
					check_place_max(*b);
				}
				else if (y.max == (*b)->next->content)
					sa(*b, "sb\n");
				else
					ra(b, "rb\n");
			}
		}
		if (!check_place_max(*b))
			swap_max_help(b, a, y.max);
	}
}

void	swap_all(t_stk **a, t_stk **b)
{
	t_stk1	y;
	int		i;

	y.i = 3;
	i = 2;
	if (ft_lstsize((t_list *) *a) >= 499)
		y.i = 5;
	y.j = ft_lstsize((t_list *) *a);
	while (y.j > 15)
	{
		len_div(&y, a, y.i, i);
		while (check_min(*a) <= y.max)
		{
			if (y.max >= (*a)->content)
			{
				pb(a, b, "pb\n");
				double_mov(a, b, y.min, y.max);
			}
			else
				ra(a, "ra\n");
		}
		y.j = ft_lstsize((t_list *) *a);
	}
	swap_all_help(a, b);
}

// void	swap_all(t_stk **a, t_stk **b)
// {
// 	t_stk1	y;
// 	int		*s;

// 	y.i = 20;
// 	y.max = 1;
// 	if (ft_lstsize((t_list *) *a) >= 499)
// 		y.i = 50;
// 	y.j = ft_lstsize((t_list *) *a);
// 	s = check_pivot(*a);
// 	while (y.j > y.i)
// 	{
// 		y.min = s[y.i * y.max++];
// 		while (check_min(*a) <= y.min && y.i)
// 		{
// 			if (y.min >= (*a)->content)
// 				pb(a, b, "pb\n");
// 			else
// 				ra(a, "ra\n");
// 		}
// 		y.j = ft_lstsize((t_list *) *a);
// 	}
// 	free(s);
// 	swap_all_help(a, b);
// }
