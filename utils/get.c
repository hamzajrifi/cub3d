/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:50:06 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/18 18:45:33 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*sec;

	j = 0;
	i = ft_strlen(str);
	sec = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		sec[j] = str[i];
		i++;
		j++;
	}
	sec[j] = '\0';
	return (sec);
}

char	*ft_strjoin1(char *str, char c)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(str);
	ptr = malloc(size + 2);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	if (c == '\n')
	{
		ptr[i] = '\0';
		free(str);
		return (ptr);
	}
	ptr[i] = c;
	ptr[i + 1] = '\0';
	free(str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	buff;
	int		rd;

	rd = read(fd, &buff, 1);
	str = ft_strdup("");
	while (rd > 0)
	{
		str = ft_strjoin1(str, buff);
		if (buff == '\n')
			break ;
		rd = read(fd, &buff, 1);
	}
	if (rd < 0)
	{
		free(str);
		return (NULL);
	}
	if (rd == 0 && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
