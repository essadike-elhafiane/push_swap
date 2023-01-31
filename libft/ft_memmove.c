/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:03:36 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/11 14:41:07 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*srcc;
	size_t	i;

	i = 0;
	str = (char *)dst;
	srcc = (char *)src;
	if (dst > src)
	{
		while (len)
		{
			str[len -1] = srcc[len -1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (str);
}
