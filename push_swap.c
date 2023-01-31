/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:29:34 by eelhafia          #+#    #+#             */
/*   Updated: 2023/01/31 15:58:30 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stk1	y;

	y.i = 1;
	y.j = 0;
	if (ac == 2)
		return (ft_split(av[1], ' '));
	else if (ac > 2)
	{
		y.spl = malloc(sizeof(char *) * ac);
		if (!y.spl)
		{
			ft_puterror("Error");
		}
		while (av[y.i])
		{
			y.spl[y.j++] = ft_strdup(av[y.i++]);
		}
		y.spl[y.j] = NULL;
		return (y.spl);
	}
	return (NULL);
}

void	distrubition_fun(t_stk **a, t_stk **b)
{
	if (ft_lstsize((t_list *)*a) <= 3)
		swap_3 (a);
	else if (ft_lstsize((t_list *)*a) <= 5)
		swap_5(a, b);
	else if (ft_lstsize((t_list *)*a) <= 40)
		swap_all(a, b);
	else
		swap_all(a, b);
}

void free_spl(char **spl)
{
	int i;

	i = 0;
	if(!spl)
		return;
	while(spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

int	main(int ac, char **av)
{
	t_stk1	y;
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	y.i = 1;
	if (ac < 2)
		ft_puterror("Error !");
	else
	{
		if (ac == 2)
			y.spl = ft_split(av[1], ' ');
		y.spl = get_input(ac, av);
		ft_check_error(y.spl);
		a = ft_init_stack(y.spl);
		if (multi_num(a))
			ft_puterror("Error");
		if (ft_lstsize((t_list *)a) == 1 || check_sort(a) == 1)
			return (0);
		distrubition_fun(&a, &b);
	}
	b = ft_new(5);
	free_spl(y.spl);
	b = function_free(b);
	return(fun_free(&b),fun_free(&a),0);
}

// 2 5 4 3 1

