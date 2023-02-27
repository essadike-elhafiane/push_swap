/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:42:51 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/17 19:35:06 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\n' || c == '\f')
		return (1);
	else
		return (0);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	a;
	int		r;

	r = 1;
	a = 0;
	i = 0;
	while (ft_isspace(str[i]))
			i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			r = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - 48;
		i++;
	}
	if (((a * r) > 2147483647) || ((a * r) < -2147483648))
		ft_error("Error !\n");
	return (a * r);
}
