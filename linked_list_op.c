/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:42:27 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/19 08:55:22 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*ft_new(int data)
{
	t_stk	*new;

	new = (t_stk *) malloc(sizeof(t_stk));
	if (!new)
		exit(1);
	new->content = data;
	new->next = NULL;
	return (new);
}

t_stk	*ft_init_stack(char **spl)
{
	t_stk	*a;
	int		i;
	t_stk	*tmp;

	i = 1;
	a = ft_new(ft_atoi(spl[0]));
	tmp = a;
	while (spl[i])
	{
		tmp->next = ft_new(ft_atoi(spl[i++]));
		tmp = tmp->next;
	}
	return (a);
}

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (*str == '-')
			str++;
		else if (*str == '+')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		while (ft_isdigit(*str))
			str++;
		if (*str == '-')
			return (0);
		if (*str == ' ')
			str++;
	}
	return (1);
}

int	multi_num(t_stk *a)
{
	t_stk	*b;
	int		c;

	while (a)
	{
		b = a;
		c = b->content;
		while (b->next)
		{
			b = b->next;
			if (b->content == c)
				return (1);
		}
		a = a->next;
	}
	return (0);
}

void	ft_check_error(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		if (!ft_str_isdigit(spl[i]))
			ft_puterror("Error\n");
		i++;
	}
}
