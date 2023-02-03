/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:59:16 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/03 16:12:49 by eelhafia         ###   ########.fr       */
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

void	swap_40(t_stk **a, t_stk **b)
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
	while (*b)
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

	y.max = 8;
	y.i = 4;
	if (ft_lstsize((t_list *) *a) >= 499)
	{
		y.max = 20;
		y.i = 8;
	}
	while (--y.max)
	{
		y.min = check_pivot(*a, y.i);
		y.j = ft_lstsize((t_list *) *a);
		swap_all_help(y.j, y.min, a, b);
	}
	swap_min(a, b);
	swap_max(b, a);
	while (*b)
		pb(b, a, "pa\n");
}

// void	swap_all(t_stk **a, t_stk **b)
// {
// 	t_stk1	y;

// 	y.max = 10;
// 	y.i = 5;
// 	if (ft_lstsize((t_list *) *a) >= 499)
// 	{
// 		y.max = 30;
// 		y.i = 10;
// 	}
// 	int i = 0;
// 	while (--y.max)
// 	{
// 		y.min = check_pivot(*a, y.i);
// 		y.j = ft_lstsize((t_list *) *a);
// 		while(y.j / 5 > 0)
// 		{
// 			i = check_place_min_of_n(*a, y.min);	
// 			while (i == 1 && y.j / 5 > 0)
// 			{
// 				if (y.min >= (*a)->content)
// 				{
// 					pb(a, b, "pb\n");
// 					y.j--;
// 				}
// 				else
// 					ra(a, "ra\n");
// 				i = check_place_min_of_n(*a, y.min);
// 				// printf("%d\n\n\n", check_place_min_of_n(*a, y.min));
// 			}	
// 			while (i == 0 && y.j / 5 > 0)
// 			{
// 				if (y.min >= (*a)->content)
// 				{
// 					pb(a, b, "pb\n");
// 					y.j--;
// 				}
// 				else
// 					rra(a, "ra\n");
// 				i = check_place_min_of_n(*a, y.min);
// 				// printf("%d\n\n\n", check_place_min_of_n(*a, y.min));
// 			}
// 		}
// 	}
// 	swap_min(a, b);
// 	swap_max(b, a);
// 	while (*b)
// 		pb(b, a, "pa\n");
// }

// void	swap_all(t_stk **a, t_stk **b)
// {
// 	t_stk1	y;

// 	y.max = 8;
// 	y.i = 4;
// 	if (ft_lstsize((t_list *) *a) >= 499)
// 	{
// 		y.max = 20;
// 		y.i = 10;
// 	}
// 	while (--y.max)
// 	{
// 		y.min = check_pivot(*a, y.i);
// 		y.j = ft_lstsize((t_list *) *a);
// 		// printf("%d\n\n", y.min);
// 		// printf("%d\n\n", y.j);
// 		while (--y.j >= 0)
// 		{
// 			if (y.min >= (*a)->content)
// 				pb(a, b, "pb\n");
// 			else
// 				ra(a, "ra\n");
// 		}
// 	}
// 	swap_min(a, b);
// 	swap_max(b, a);
// 	while (*b)
// 		pb(b, a, "pa\n");
// }
