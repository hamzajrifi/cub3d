/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:58:39 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/18 18:24:59 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		i++;
	}
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	k = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	str = (char *)malloc(i + j +1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (!str)
		return (NULL);
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	free((char *)s1);
	return (str);
}
