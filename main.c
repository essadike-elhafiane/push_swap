/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:07:29 by eelhafia          #+#    #+#             */
/*   Updated: 2023/03/03 14:49:41 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stk1	y;
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	y.i = 1;
	if (ac < 2)
		return (0);
	y.spl = get_input(ac, av);
	ft_check_error(y.spl);
	a = ft_init_stack(y.spl);
	free_spl(y.spl);
	if (multi_num(a))
		ft_puterror("Error\n");
	if (ft_lstsize((t_list *)a) == 1 || check_sort(a) == 1)
		return (fun_free(&a), 0);
	distrubition_fun(&a, &b);
	fun_free(&a);
	return (0);
}
