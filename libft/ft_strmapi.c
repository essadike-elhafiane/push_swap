/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:13:01 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/08 21:39:42 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ss;
	unsigned int	i;

	ss = (char *)s;
	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc((ft_strlen(s)+1) * sizeof(char));
	if (!str)
		return (0);
	while (ss[i])
	{
		str[i] = f(i, ss[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
