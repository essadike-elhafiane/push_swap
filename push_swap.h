/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:27:54 by eelhafia          #+#    #+#             */
/*   Updated: 2023/01/30 14:28:44 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct stack
{
	int				content;
	struct stack	*next;
}	t_stk;

typedef struct stack1
{
	int		i;
	int		j;
	int		min;
	int		max;
	char	**spl;
}	t_stk1;

void	sa(t_stk *a, char *s);
void	rra(t_stk **a, char *s);
void	ra(t_stk **a, char *s);
int		check_min(t_stk *a);
int		check_max(t_stk *a);
int		check_sort(t_stk *a);
int		check_place_min(t_stk *a);
int		check_place_max(t_stk *b);
int		check_pivot(t_stk *a, int deff_pivot);
int		chek_sort_arr(int *s, int j);
void	swap_5(t_stk **a, t_stk **b);
void	swap_3(t_stk **a);
void	swap_min(t_stk **a, t_stk **b);
void	swap_40(t_stk **a, t_stk **b);
void	swap_max(t_stk **b, t_stk **a);
void	swap_all(t_stk **a, t_stk **b);
void	swap_max_help(t_stk **b, t_stk **a, int max);
void	swap_min_help(t_stk **a, t_stk **b, int min);
void	pb(t_stk **a, t_stk **b, char *s);
t_stk	*ft_new(int data);
int		multi_num(t_stk *a);
void	ft_check_error(char **spl);
t_stk	*ft_init_stack(char **spl);
void	ft_puterror(char *s);
void	fun_free(t_stk **a);
t_stk	*function_free(t_stk *tmp);
t_stk	*ft_lstlasttt(t_stk *lst);
t_stk	*ft_lstlastt(t_stk *lst);
#endif