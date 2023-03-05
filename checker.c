/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:35:10 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/28 22:44:50 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_op_help(char *s, t_stk **a, t_stk **b)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rra(b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n' )
	{
		rra(a, 0);
		rra(b, 0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
	{
		ra(a, 0);
		ra(b, 0);
	}
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(a, b, 0);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pb(b, a, 0);
	else if (((s[0] == 's' && s[1] == 'a')
			|| (s[0] == 's' && s[1] == 'b')
			|| (s[0] == 's' && s[1] == 's')) && s[2] == '\n')
		return ;
	else
	{
		write(1, "Error\n", 7);
		exit(1);
	}
}

void	check_op(char *s, t_stk **a, t_stk **b)
{
	int	lena;
	int	lenb;

	lena = ft_lstsize((t_list *) *a);
	lenb = ft_lstsize((t_list *) *b);
	if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(a, 0);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		ra(b, 0);
	else if (s[0] == 's' && s[1] == 'a' && s[2] == '\n' && (lena > 1))
		sa(*a, 0);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n' && (lenb > 1))
		sa(*b, 0);
	else if (s[0] == 's' && s[1] == 's'
		&& s[2] == '\n' && (lena > 1) && (lenb > 1))
	{
		sa(*a, 0);
		sa(*b, 0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(a, 0);
	else
		check_op_help(s, a, b);
}

void	read_line(t_stk **a, t_stk **b)
{
	char	*op;
	int		len;
	int		lena;

	len = ft_lstsize((t_list *) *a);
	op = get_next_line(0);
	while (op)
	{
		check_op(op, a, b);
		free(op);
		op = get_next_line(0);
	}
	lena = ft_lstsize((t_list *) *a);
	if (check_sort(*a) && lena == len)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;
	t_stk1	y;

	if (ac < 2)
		return (0);
	y.spl = get_input(ac, av);
	ft_check_error(y.spl);
	a = ft_init_stack(y.spl);
	free_spl(y.spl);
	if (multi_num(a))
		ft_puterror("Error\n");
	read_line(&a, &b);
	fun_free(&a);
	return (0);
}
