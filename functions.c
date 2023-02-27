/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:19:11 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/26 23:35:56 by eelhafia         ###   ########.fr       */
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

void	swap_all_help(t_stk **a, t_stk **b)
{
	swap_min(a, b);
	swap_max(b, a);
	while (*b)
		pb(b, a, "pa\n");
}

void	swap_30(t_stk **a, t_stk **b)
{
	swap_min(a, b);
	while (*b)
		pb(b, a, "pa\n");
}

void	arg_empty(char *s)
{
	while (*s == ' ' || *s == '-')
		s++;
	if (*s == '\0')
	{
		write(1, "Error arg is empty !\n", 21);
		exit(1);
	}
}

void	rr(t_stk **a, t_stk **b, char *s)
{
	ra(a, 0);
	ra(b, 0);
	ft_putstr_fd(s, 1);
}
