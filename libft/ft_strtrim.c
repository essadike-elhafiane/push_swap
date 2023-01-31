/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:01:43 by eelhafia          #+#    #+#             */
/*   Updated: 2022/11/08 21:35:09 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char *s1, char *set)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	while (set[i])
	{
		while (set[i] == s1[b])
		{
				b++;
				i = 0;
		}
		i++;
	}
	return (b);
}

static int	end(char *s1, char *set)
{
	int	i;
	int	b;

	b = ft_strlen(s1);
	i = 0;
	while (set[i])
	{
		while (set[i] == s1[b -1])
		{
				b--;
				i = 0;
			if (b == 0)
				return (0);
		}
		i++;
	}
	return (b);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	a = start ((char *)s1, (char *)set);
	b = end ((char *)s1, (char *)set);
	return (ft_substr(s1, a, (b - a)));
}
