/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:14:22 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/08 21:40:01 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;

	if (!dstsize)
		return (ft_strlen(src));
	a = ft_strlen(dst);
	i = 0;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (src[i] && i < dstsize - a -1)
	{
		if (a < dstsize)
		{
			dst[a + i] = src[i];
		}
		i++;
	}
	dst[a + i] = '\0';
	return (a + ft_strlen(src));
}
