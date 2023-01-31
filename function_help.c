/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:33:21 by eelhafia          #+#    #+#             */
/*   Updated: 2023/01/07 22:35:39 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	push_arr(t_stk *a, int *s)
{
	int	i;

	i = 0;
	while (a)
	{
		s[i++] = a->content;
		a = a->next;
	}
}

int	check_pivot(t_stk *a, int deff_pivot)
{
	t_stk1	y;
	int		*s;

	y.max = ft_lstsize((t_list *)a);
	if(y.max <= deff_pivot)
		return 0;
	s = malloc(y.max * sizeof(int));
	push_arr(a, s);
	y.i = -1;
	while (!chek_sort_arr(s, y.max))
	{
		while (y.i++ < y.max - 1)
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
	y.i = 0;
	while (y.i < y.max / deff_pivot)
		y.i++;
	return (y.min = s[y.i], free(s), y.min);
}
