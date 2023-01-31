/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:59:16 by eelhafia          #+#    #+#             */
/*   Updated: 2023/01/31 15:48:19 by eelhafia         ###   ########.fr       */
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
int cherche_front(t_stk *a, int min)
{
	t_stk1	y;

	y.max = 0;
	if(!(a)->next->content)
		return(155);
	y.i = ft_lstsize((t_list *)a);
	while (y.max < y.i)
	{
		if (a->content <= min)
			return (y.max);
		a = a->next;
		y.max++;
	}
	return (y.max);
}

int cherche_back(t_stk *a, int min)
{
	t_stk1	y;

	y.max = 0;
	void *c;
	t_stk *m;
	if(!a)
		return(155);
	y.i = ft_lstsize((t_list *)a);
	while (y.max < y.i-3)
	{
		y.min = ft_lstlasttt(a)->content;
		if (y.min <= min)
			return (y.max);
		c = ft_lstlasttt(a);
		m = ft_lstlastt(a);
		m->next = NULL;
		free(c);
		y.max++;
	}
	return (y.max);
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
// void sss(t_stk **a, t_stk **b, char *s)
// {
	
// 	ft_putstr_fd (s, 1);
// }
void	swap_all(t_stk **a, t_stk **b)
{
	t_stk1	y;

	y.max = 8;
	y.i = 4;
	if (ft_lstsize((t_list *) *a) >= 499)
	{
		y.max = 20;
		y.i = 6;
	}
	int i;
	
	while (--y.max)
	{
		y.min = check_pivot(*a, y.i);
		// if(y.min == 0)
		// 	y.min = check_max(*a);
		// int x = check_min(*a);
		y.j = ft_lstsize((t_list *) *a);
		// if(y.j <= 20)
		// 	y.min = check_max(*a);
		while (y.j--)
		{
			i = 0;
			
			while(check_place_min_of_n(*a, y.min) && i == 0 )
			{
				if (y.min >= (*a)->content)
				{
					pb(a, b, "pb\n");
					i = 1;
				}
				else if(check_place_min_of_n(*a, y.min))
					ra(a, "ra\n");
			}
			// printf("front = %d || back = %d \n\n", cherche_front(*a, y.min) ,cherche_back(*a, y.min));
			// // return ;
			// while( i == 0 )
			// {
			// 	if (y.min >= (*a)->content)
			// 	{
			// 		pb(a, b, "pb\n");
			// 		i = 1;
			// 	}
			// 	else if(!check_place_min_of_n(*a, y.min))
			// 		rra(a, "rra\n");
			// 	// printf("%d\n\n", check_place_min_of_n(*a, y.min));
			// }
		}
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

// 	y.max = 10;
// 	y.i = 5;
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
