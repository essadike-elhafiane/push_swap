/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:19:11 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/03 16:12:01 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_spl(char **spl)
{
	int	i;

	i = 0;
	if (!spl)
		return ;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

int	check_place_min_of_n(t_stk *a, int min)
{
	t_stk1	y;

	y.max = 0;
	y.i = ft_lstsize((t_list *)a);
	while (y.max <= y.i / 2)
	{
		if (a->content <= min)
			return (1);
		a = a->next;
		y.max++;
	}
	return (0);
}

void	swap_all_help(int j, int min, t_stk **a, t_stk **b)
{
	int		i;

	while (j--)
	{
		i = 0;
		while (check_place_min_of_n(*a, min) && i == 0)
		{
			if (min >= (*a)->content)
			{
				pb(a, b, "pb\n");
				i = 1;
			}
			else if (check_place_min_of_n(*a, min))
				ra(a, "ra\n");
		}
	}
}
