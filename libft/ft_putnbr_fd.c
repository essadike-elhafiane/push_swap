/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:13:10 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/08 21:40:38 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		a = n * -1;
		ft_putchar_fd ('-', fd);
	}
	if (a >= 0 && a <= 9)
	{
		ft_putchar_fd(a + 48, fd);
	}
	if (a > 9)
	{
		ft_putnbr_fd (a / 10, fd);
		ft_putnbr_fd (a % 10, fd);
	}
}
