/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:50:15 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/17 15:58:17 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strrchr(char *str, int c)
{
	char	*st;
	int		i;

	st = (char *)str;
	i = strlen(st);
	while (i >= 0)
	{
		if (st[i] == (unsigned char)c)
			return (st + i);
		i--;
	}
	return (NULL);
}

char	*ft_strchr(char *str, int c)
{
	char	*st;
	int		i;

	st = (char *)str;
	i = 0;
	while (str[i])
	{
		if (st[i] == (unsigned char)c)
			return (st + i);
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find, int size)
{
	int	i;
	int	j;

	i = 0;
	j = strlen(str);
	while (str[i])
	{
		if ((i + size) == j)
			break ;
		i++;
	}
	if (ft_strcmp((str + i), to_find) == 0)
		return (&str[i]);
	return (0);
}

char	*ft_strstr2(char *str, char *to_find, int size)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		a++;
		while (str[i + j] && to_find[j] == str[i + j] && i < size)
		{
			if (to_find[j + 1] == '\0' && (str[i + j + 1] == ' '
					|| str[i + j + 1] == '\t'))
				return (&str[i]);
			j++;
		}
		if (i < size)
			return (0);
		j = 0;
		i++;
	}
	return (0);
}
