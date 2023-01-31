/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:20:56 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/08 21:44:51 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	llen(long n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		n *= -1;
		j++;
	}
	while (n > 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	long	a;
	int		len;
	char	*str;

	a = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = llen(a);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (a < 0)
	{
			a = a * -1;
			str[0] = '-';
	}
	str[len] = '\0';
	while (a > 0)
	{
		str[len - 1] = a % 10 +48;
		a = a / 10;
		len--;
	}
	return (str);
}
