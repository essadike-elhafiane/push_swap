/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:29:34 by eelhafia          #+#    #+#             */
/*   Updated: 2023/03/03 14:50:51 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	div_chan(int div)
{
	int	i;

	i = 7;
	if (div <= 400)
		i = 6;
	if (div <= 200)
		i = 3;
	return (i);
}

void	swap_3_help(int min, int i, int max, t_stk **a)
{
	if (min == (*a)->content && max
		!= (*a)->next->next->content && i == 3)
	{
		sa(*a, "sa\n");
		ra(a, "ra\n");
	}
	else if (max != (*a)->content && max
		!= (*a)->next->next->content && i == 3)
		rra(a, "rra\n");
	else if (min != (*a)->next->next->content
		&& max == (*a)->content && i == 3)
		ra(a, "ra\n");
}

void	swap_3(t_stk **a)
{
	t_stk1	y;

	y.max = check_max(*a);
	y.i = ft_lstsize((t_list *)*a);
	y.min = check_min(*a);
	if (y.i <= 3)
	{
		if (y.i == 2 && y.min != (*a)->content)
			sa(*a, "sa\n");
		else if (y.min != (*a)->content && y.max
			== (*a)->next->next->content && y.i == 3)
			sa (*a, "sa\n");
		else if (y.min == (*a)->next->next->content && y.max
			== (*a)->content && y.i == 3)
		{
			sa(*a, "sa\n");
			rra(a, "rra\n");
		}
		else
			swap_3_help(y.min, y.i, y.max, a);
	}
}

char	**get_input(int ac, char **av)
{
	char	*s;
	char	**str;
	int		x;

	s = NULL;
	x = 0;
	if (ac > 1)
	{
		while (++x < ac)
		{
			arg_empty(av[x]);
			s = ft_strjoin(s, av[x]);
		}
		str = ft_split(s, ' ');
		free(s);
		return (str);
	}
	return (NULL);
}

void	distrubition_fun(t_stk **a, t_stk **b)
{
	if (ft_lstsize((t_list *)*a) <= 3)
		swap_3 (a);
	else if (ft_lstsize((t_list *)*a) <= 5)
		swap_5(a, b);
	else if (ft_lstsize((t_list *)*a) <= 30)
		swap_30(a, b);
	else
		swap_all(a, b);
}
