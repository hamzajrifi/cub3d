/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:49:56 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/17 15:49:57 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	check(const char *s, char *su, int sta, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= sta && j < len)
		{
			su[j] = s[i];
			j++;
		}
		i++;
	}
	su[j] = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*sub;

	a = len + 1;
	if (s == NULL)
		return (NULL);
	if (a > ft_strlen(s))
		a = ft_strlen((s) + 1);
	sub = (char *)malloc(sizeof(char) * a + 1);
	if (!sub)
		return (NULL);
	check(s, sub, start, len);
	return (sub);
}
