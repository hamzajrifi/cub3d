/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:14:42 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/15 02:26:51 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

long	ft_strlen(const char *str)
{
	long	i;

	i = 0 ;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(len_s1 * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	len_s;

	j = 0;
	len_s = 0;
	lendst = ft_strlen(dst);
	i = ft_strlen(dst);
	while (src[len_s] != '\0')
		len_s++;
	if (dstsize == 0 || dstsize <= lendst)
		return (dstsize + len_s);
	while (src[j] && ((dstsize - lendst > 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
		dstsize--;
	}
	dst[i] = '\0';
	return (lendst + len_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		len;
	int		len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1);
	len1 = ft_strlen((char *)s2);
	ptr = (char *)malloc(sizeof(char) * (len + len1 + 1));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	ft_strlcat(ptr, (char *)s1, len + 1);
	ft_strlcat(ptr, (char *)s2, len + len1 + 1);
	free_mytab(&s1);
	return (ptr);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		lens;
	char	*p;

	if (!s)
		return (0);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	if (lens < start + len)
		len = lens;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	i = 0;
	while (s[start + i] && len > 0)
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
