/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:51:51 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/08 21:38:56 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		b;

	str = (char *)s;
	b = ft_strlen(str);
	while (b != 0)
	{
		if (str[b] == (char) c)
			return (str + b);
		b--;
	}
	if (str[0] == (char) c)
		return (str);
	return (0);
}
