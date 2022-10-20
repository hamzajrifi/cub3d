/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:56:57 by hjrifi            #+#    #+#             */
/*   Updated: 2021/11/16 19:29:26 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_copy(char *ptr, char const *s, unsigned int start, size_t len)
{
	int		j;
	size_t	k;

	j = 0;
	k = 0;
	while (s[j])
	{
		if (s[j] == s[start] && k < len)
		{
			ptr[k] = s[start];
			k++;
			start++;
		}
		j++;
	}
	ptr[k] = '\0';
}

char	*ft_libft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;

	a = len + 1;
	if (!s)
		return (NULL);
	if (a >= ft_strlen(s))
		a = ft_strlen(s);
	ptr = (char *)malloc(a);
	if (!ptr)
		return (NULL);
	ft_copy(ptr, s, start, len);
	return (ptr);
}
